#include "song.h"

int main()
{
    int choice;
    bool flag = true;
    char ch;
    Song *songs;
    do
    {
        cout << "Play Song " << endl;
        cout << "1. Based On Playlist" << endl;
        cout << "2. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "a. Melody Songs" << endl;
            cout << "b. Rock Music" << endl;
            cout << "c. Love Songs" << endl;
            cout << "d. Love & Rock Songs" << endl;
            cin >> ch;
            switch (ch)
            {
            case 'a':
                songs = new Melody[20];
                songs = melodySongs(songs);
                playOnTrack(songs);
                //  delete [] songs;
                break;

            case 'b':
                songs = new Rock[20];
                songs = rockSongs(songs);
                playOnTrack(songs);
                //  delete [] songs;
                break;

            case 'c':
                songs = new Love[20];
                songs = loveSongs(songs);
                playOnTrack(songs);
                //  delete [] songs;
                break;

            case 'd':
                songs = new LoveAndRock[20];
                songs = loveAndRockSongs(songs);
                playOnTrack(songs);
                //  delete [] songs;
                break;

            default:
                cout << "Enter a valid choice" << endl;
            }
            break;

        case 2:
            flag = false;
            break;

        default:
            cout << "Enter a valid choice" << endl;
        }

    } while (flag);

    return 0;
}