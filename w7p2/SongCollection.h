// Workshop 7 part2
// SongCollection.h
// Junwoo Lee
// 124395203
// 11/13/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <string>
#include <vector>
#include <list>
namespace sdds {
	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		size_t m_releaseYear;
		size_t m_length;
	};

	class SongCollection {
		std::vector<Song> m_songs;
	public:
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
		void sort(const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& artist) const;
		std::list<Song> getSongsForArtist(const std::string& artist) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);


}


#endif