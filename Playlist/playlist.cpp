#include "song.h"

Button::Button()
{
  this->status = false;
}

void Button::setStatus(bool status)
{
  this->status = status;
}

bool Button::getStatus()
{
  return this->status;
}

void Song::setButton(bool flag)
{
  this->button.setStatus(flag);
}

bool Song::getButton()
{
  return this->button.getStatus();
}

Song::Song()
{
}

Song::Song(int id, string name)
{
  this->_id = id;
  this->_name = name;
}

string Song::getName()
{
  return this->_name;
}

int Song::getId()
{
  return this->_id;
}

Melody::Melody()
{
  Default Constructor;
}

Melody::Melody(int id, string name) : Song(id, name)
{
  //this->fluteTune = fluteTune;
}

// string Melody::getFluteTune()
// {

//   return "Good Flute Tune";
// }

Rock::Rock()
{
}

Rock::Rock(int id, string name) : Song(id, name)
{
  //this->fastBeats = fastBeats;
}

Love::Love()
{
}

// int Rock::getFastBeats()
// {

//   return 3;
// }

Love::Love(int id, string name) : Song(id, name)
{
  //this->scenarie = scenarie;
}

// string Love::getScenarie()
// {
//   return "High Scenarie";
// }

LoveAndRock::LoveAndRock()
{
}

LoveAndRock::LoveAndRock(int id, string name) : Song(id, name)
{
  //this->scenarie = scenarie;
  //this->fastBeats = fastBeats;
}

// int LoveAndRock::getFastBeats()
// {
//   return 4;
// }

// string LoveAndRock::getScenarie()
// {
//   return "Good Scenarie";
// }

Song *
melodySongs(Song *songs)
{
  int id;
  int type;
  string name;
  ifstream in;
  in.open("song.txt", ios::in);

  int flag = 0, i = 0;

  if (!in)
    cout << "ERROR! No file opened" << endl;
  else
  {
    while (in)
    {
      in >> id;
      in >> type;
      getline(in, name);
      if (type == 1)
      {
        flag = 1;
        songs[i++] = Melody(id, name);
        cout<<songs[i-1].getId()<<songs[i-1].getName()<<endl;
        //  songs[i-1].display();
      }
    }

    if (flag == 0 || id == 0 || name == "")
      cout << "No Data there" << endl;
    else
      cout << "Data Copied Successfully to Array" << endl;

    in.close();
  }

  s_play = i;
  //  cout<<i<<endl<<s_play<<endl;

  return songs;
}

Song *
rockSongs(Song *songs)
{
  int id;
  int type;
  string name;
  ifstream in;
  in.open("song.txt", ios::in);

  int flag = 0, i = 0;

  if (!in)
    cout << "ERROR! No file opened" << endl;
  else
  {
      int z=0;
    while (in)
    {
      // cout<<"MO"<<endl;
      in >> id;
      in >> type;
      getline(in, name);
      if (type == 2)
      {
        // cout<<"z- "<<++z<<endl;
        flag = 1;
        songs[i++] = Rock(id, name);
        // cout<<songs[i-1].getId()<<songs[i-1].getName()<<endl;
        songs[i-1].display();
      }
    }

    if (flag == 0 || id == 0 || name == "")
      cout << "No Data there" << endl;
    else
      cout << "Data Copied Successfully to Array" << endl;

    in.close();
  }

  s_play = i;
// cout<<"i- "<<i<<endl;
  return songs;
}

Song *
loveSongs(Song *songs)
{
  int id;
  int type;
  string name;
  ifstream in;
  in.open("song.txt", ios::in);

  int flag = 0, i = 0;
  // fseek (fp, 0, SEEK_SET);

  if (!in)
    cout << "ERROR! No file opened" << endl;
  else
  {
    while (in)
    {
      in >> id;
      in >> type;
      getline(in, name);
      if (type == 3)
      {
        flag = 1;
        songs[i++] = Love(id, name);
        // cout<<id<<name<<endl;
        songs[i-1].display();
      }
    }

    if (flag == 0 || id == 0 || name == "")
      cout << "No Data there" << endl;
    else
      cout << "Data Copied Successfully to Array" << endl;

    in.close();
  }

  s_play = i;

  return songs;
}

Song *
loveAndRockSongs(Song *songs)
{
  int id;
  int type;
  string name;
  ifstream in;
  in.open("song.txt", ios::in);

  int flag = 0, i = 0;

  //  Song *temp = new LoveAndRock[20];

  // fseek (fp, 0, SEEK_SET);

  if (!in)
    cout << "ERROR! No file opened" << endl;
  else
  {
    while (in)
    {
      in >> id;
      in >> type;
      getline(in, name);
        // cout<<id<<name<<endl;
      if (type == 2 || type == 3)
      {
        //  cout<<"i- "<<i<<endl;
        flag = 1;
        songs[i++] = LoveAndRock(id, name);
        // cout<<id<<name<<endl;
        // cout<<songs[i-1].getId()<<songs[i-1].getName()<<endl; 
        songs[i-1].display();
      }
    }

    if (flag == 0 || id == 0 || name == "")
      cout << "No Data there" << endl;
    else
      cout << "Data Copied Successfully to Array" << endl;

    in.close();
  }

  s_play = i;

  //delete[]songs;
  // songs = temp;

  return songs;
}

/*
void
resetSongs (Song * songs)
{
  for (int i = 0; i < s_count; i++)
    {
      //if (songs[i].getButton ())
	songs[i].setButton (false);
    }
}

void
playOnId (Song * songs, int id)
{
  int ch, flag = 0;
  for (int i = 0; i < s_count; i++)
    {
      if (songs[i].getId () == id)
	{
	  songs[i].setButton (true);
	  cout << songs[i].getName () << " Is Playing" << endl;
	  cout << "1. PlayNext" << endl;
	  cout << "2. Quit" << endl;
	  cin >> ch;
	  switch (ch)
	    {
	    case 1:
	      id++;
	      break;

	    case 2:
	      flag = 1;
	      break;

	    default:
	      cout << "Enter a valid choice" << endl;
	    }
	  if (flag == 1)
	    break;
	}
    }

  if (flag == 0)
    cout << "Playlist Ended No Song Found" << endl;
}
*/

void Melody::display()
{
  cout << endl
       << "Melody class display invoked" << endl;
  cout << this->getId() << this->getName() << " is playing " << endl;
}

void Rock::display()
{
  cout << endl
       << "Rock class display invoked" << endl;
  cout << this->getId() << this->getName() << " is playing " << endl;
}

void Love::display()
{
  cout << endl
       << "Love class display invoked" << endl;
  cout << this->getId() << this->getName() << " is playing " << endl;
}

void LoveAndRock::display()
{
  cout << endl
       << "Love & Rock class display invoked" << endl;
  cout << this->getId() << this->getName() << " is playing " << endl;
}

void playOnTrack(Song *songs)
{
  int ch, flag = 0;
  for (int i = 0; i < s_play; i++)
  {
    songs[i].setButton(true);

    // cout << songs[i].getId() << songs[i].getName() << " Is Playing" << endl;
    songs[i].display();
    cout << "1. PlayNext" << endl;
    cout << "2. Quit" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:

      break;

    case 2:

      flag = 1;
      break;

    default:
      cout << "Enter a valid choice" << endl;
    }
    songs[i].setButton(false);
    if (flag == 1)
      break;
  }

  if (flag == 0)
    cout << "PlayList Ended" << endl;
}