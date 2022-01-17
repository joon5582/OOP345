#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <string>
#include <vector>
namespace sdds {
	struct Song {
		std::string artist;
		std::string title;
		std::string album;
		double price;
		size_t releaseYear;
		size_t length;
	};

	class SongCollection {
		std::vector<Song> m_songs;
	public:
		SongCollection(std::string filename);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);


}


#endif