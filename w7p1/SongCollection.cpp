#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "SongCollection.h"

using namespace std;
namespace sdds {

	void trim(string& src)
	{
		if (src.length() > 0) {
			int begin = src.find_first_not_of(' ');
			int end = src.find_last_not_of(' ');
			if (begin == -1) src = "";
			else src = src.substr(begin, end - begin + 1);
		}
	}

	SongCollection::SongCollection(string filename)
	{
		ifstream file(filename);
		if (!file)
		{
			cerr << "ERROR: Cannot open the file named " << filename << endl;
			exit(-1);
		}
		Song tempSong;
		string temp;
		do
		{
			getline(file, temp);
			if (file) {
				tempSong.title = temp.substr(0, 25);
				trim(tempSong.title);
				tempSong.artist = temp.substr(25, 25);
				trim(tempSong.artist);
				tempSong.album = temp.substr(50, 25);
				trim(tempSong.album);
				try {
					tempSong.releaseYear = stoi(temp.substr(75, 5));
				}
				catch (invalid_argument&) {
					tempSong.releaseYear = 0;
				}
				tempSong.length = stoi(temp.substr(80, 5));
				tempSong.price = stod(temp.substr(85, 5));
				m_songs.push_back(tempSong);
			}

		} while (file);
		file.close();
	}

	void SongCollection::display(ostream& out) const
	{
		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& song) {out << song; });
	}


	ostream& operator<<(ostream& out, const Song& theSong)
	{
		out << "| " << setw(20) << left << theSong.title << " | "
			<< setw(15) << left << theSong.artist << " | "
			<< setw(20) << left << theSong.album << " | " << setw(6) << right;
		if (theSong.releaseYear == 0) out << ' ';
		else out << theSong.releaseYear;
		out << " | " << theSong.length / 60 << ':' << setfill('0') << setw(2)  << theSong.length % 60
			<<setfill(' ') << " | " << theSong.price << " |" << endl;
		return out;
	}

}