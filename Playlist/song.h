#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;
using std::to_string;
#define SIZE 50

static int
    s_play = 0,
    s_count = 0, max = 1000;

class Button
{
    bool
        status;

public:
    Button();
    void
    setStatus(bool);
    bool
    getStatus();
};

class Song
{
private:
    int
        _id;
    string _name;
    Button button;
    int
        _type;

public:
    Song();
    Song(int, string);
    Song(string, int);
    Song(Song &);
    static int
    generateId();
    int
    getId();
    string getName();
    void
    setButton(bool);
    bool
    getButton();
    virtual void
    display() = 0;

    friend ostream &operator<<(ostream &out, const Song &s);
    friend istream &operator>>(istream &in, Song &s);
    //  friend int
    //  operator == (Song, Song);
};

class Melody : virtual public Song
{
    // string
    //   fluteTune;

public:
    Melody();
    Melody(int, string);
    // string getFluteTune();
    void display();
};

class Rock : virtual public Song
{
    // int
    //   fastBeats;

public:
    Rock();
    Rock(int, string);
    // int getFastBeats();
    void display();
};

class Love : virtual public Song
{
    // string
    //   scenarie;

public:
    Love();
    Love(int, string);
    // string getScenarie();
    void display();
};

class LoveAndRock : public Love, public Rock
{
    // int
    //   fastBeats;
    // string
    //   scenarie;

public:
    LoveAndRock();
    LoveAndRock(int, string);
    // int getFastBeats();
    // string getScenarie();
    void display();
};

Song *
deleteSong(Song *, int);
//void
//insertInFile (Song);
void addSong(Song *, string, int);
Song *
fileToArray(Song *);
void displayFromFile();
void displayFromArray(Song *);
void deleteFromFile(Song *);
Song *
melodySongs(Song *);
Song *
rockSongs(Song *);
Song *
loveSongs(Song *);
Song *loveAndRockSongs(Song *);
//void resetSongs (Song *);
void playOnTrack(Song *);

#endif