// Workshop 7 part2
// SongCollection.cpp
// Junwoo Lee
// 124395203
// 11/13/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


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
				tempSong.m_title = temp.substr(0, 25);
				trim(tempSong.m_title);
				tempSong.m_artist = temp.substr(25, 25);
				trim(tempSong.m_artist);
				tempSong.m_album = temp.substr(50, 25);
				trim(tempSong.m_album);
				try {
					tempSong.m_releaseYear = stoi(temp.substr(75, 5));
				}
				catch (invalid_argument&) {
					tempSong.m_releaseYear = 0;
				}
				tempSong.m_length = stoi(temp.substr(80, 5));
				tempSong.m_price = stod(temp.substr(85, 5));
				m_songs.push_back(tempSong);
			}

		} while (file);
		file.close();
	}

	void SongCollection::display(ostream& out) const
	{
		size_t totalPlaytime = 0;
		for_each(m_songs.begin(), m_songs.end(), [&out, &totalPlaytime](const Song& song) {out << song<<endl; totalPlaytime += song.m_length; });
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: " << totalPlaytime / 3600 << ':' << (totalPlaytime % 3600) / 60 << ':' << totalPlaytime % 60 << " |\n";
	}

	void SongCollection::sort(const std::string& field)
	{
		std::sort(m_songs.begin(), m_songs.end(), [&field](const Song& song1, const Song& song2)
			{
				if (field == "album") return song1.m_album < song2.m_album;
				else if (field == "length") return song1.m_length < song2.m_length;
				else return song1.m_title < song2.m_title;
			}
		);
	}

	void SongCollection::cleanAlbum()
	{
		Song temp;
		replace_if(m_songs.begin(), m_songs.end(), [&temp](const Song& song) {temp = song; temp.m_album = ""; return song.m_album == "[None]"; }, temp);
	}

	bool SongCollection::inCollection(const std::string& artist) const
	{
		return any_of(m_songs.begin(), m_songs.end(), [&artist](const Song& song) {return song.m_artist == artist; });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
	{
		std::list<Song> songlist (m_songs.size());
		auto it = copy_if(m_songs.begin(), m_songs.end(), songlist.begin(), [&artist](const Song& song) {return song.m_artist == artist; });
		songlist.resize(std::distance(songlist.begin(), it));
		return songlist;
	}

	ostream& operator<<(ostream& out, const Song& theSong)
	{
		out << "| " << setw(20) << left << theSong.m_title << " | "
			<< setw(15) << left << theSong.m_artist << " | "
			<< setw(20) << left << theSong.m_album << " | " << setw(6) << right;
		if (theSong.m_releaseYear == 0) out << ' ';
		else out << theSong.m_releaseYear;
		out << " | " << theSong.m_length / 60 << ':' << setfill('0') << setw(2) << theSong.m_length % 60
			<< setfill(' ') << " | " << theSong.m_price << " |";
		return out;
	}

}