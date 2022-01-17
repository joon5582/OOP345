#include <fstream>
#include <string>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		ifstream is(file);
		string temp;
		string itemname;
		string from;
		string to;
		size_t pos = 0;
		bool more = true;
		Utilities util;
		util.setDelimiter('|');
		vector<Workstation*> remainfirst;
		while (!is.eof()) {
			getline(is, temp);
			pos = 0;
			more = true;
			itemname = util.extractToken(temp, pos, more);
			Workstation* wp;
			wp = *(find_if(stations.begin(), stations.end(), [&](Workstation* sp) {
				return sp->getItemName() == itemname;
				}));
			activeLine.push_back(wp);
			remainfirst.push_back(wp);
		}
		is.seekg(ios::beg);
		while (!is.eof()) {
			getline(is, temp);
			pos = 0;
			more = true;
			from = util.extractToken(temp, pos, more);
			if (more) {
				Workstation* fromWp, * toWp;
				to = util.extractToken(temp, pos, more);
				toWp = *(find_if(activeLine.begin(), activeLine.end(), [&](Workstation* wp) {
					return wp->getItemName() == to;
				}));

				remainfirst.erase(remove(remainfirst.begin(), remainfirst.end(), toWp), remainfirst.end());
				fromWp = *(find_if(activeLine.begin(), activeLine.end(), [&](Workstation* wp) {
					return wp->getItemName() == from;
					}
				));
				fromWp->setNextStation(toWp);
			}
		}
		m_cntCustomerOrder = pending.size();
		m_firstStation = remainfirst.front();
	}
	void LineManager::linkStations()
	{
		std::vector<Workstation*> tempLine;
		Workstation* tp;
		tempLine.push_back(m_firstStation);
		while ((tp = tempLine.back()->getNextStation())) tempLine.push_back(tp);
		activeLine.clear();
		activeLine = tempLine;
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t count{};
		count++;
		os << "Line Manager Iteration: " << count << endl;
		if (!pending.empty()) {
			*m_firstStation += move(pending.front());
			pending.pop_front();
		}

		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws) {
			ws->fill(os);
			});
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws) {
			ws->attemptToMoveOrder();
			});

	
		
		return completed.size() + incomplete.size() == m_cntCustomerOrder;
	}
	void LineManager::display(std::ostream& os) const
	{
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* ws) {
			ws->display(os);
			});
	}
}