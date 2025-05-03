#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Song {
    string name;
    int priority;
};

vector<Song> karaoke_queue;

bool isEmpty() {
    return karaoke_queue.empty();
}

string enqueue(string song_name, int priority) {
    Song new_song = {song_name, priority};
    karaoke_queue.push_back(new_song);
    sort(karaoke_queue.begin(), karaoke_queue.end(), [](const Song &a, const Song &b) {
        return a.priority < b.priority;
    });
    return "A new song has been added to the queue.";
}

string dequeue() {
    if (isEmpty()) {
        return "There is no song in the queue. Try adding first.";
    }
    string song_name = karaoke_queue.front().name;
    karaoke_queue.erase(karaoke_queue.begin());
    return song_name;
}

int main() {
    cout << enqueue("rainbow", 2) << endl;
    cout << enqueue("the gift", 1) << endl;
    cout << enqueue("i love you, goobye", 3) << endl;

    cout << "Songs in the queue:" << endl;
    for (const auto &song : karaoke_queue) {
        cout << song.name << " (Priority " << song.priority << ")" << endl;
    }

    cout << dequeue() << endl;
    cout << dequeue() << endl;  
    cout << dequeue() << endl;
    cout << dequeue() << endl;

    return 0;
}
