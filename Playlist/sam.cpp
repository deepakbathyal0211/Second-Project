#include "song.h"

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
