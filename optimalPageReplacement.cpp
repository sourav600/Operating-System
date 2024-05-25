#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the page that will not be used for the longest period of time in the future
int predict(vector<int>& pages, vector<int>& frames, int cur_Idx) {
    int farthest = cur_Idx;
    int pageToReplace = -1;

    for (int i = 0; i < frames.size(); ++i) {
        int j;
        for (j = cur_Idx; j < pages.size(); ++j) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pageToReplace = i;
                }
                break;
            }
        }
        // If a frame is not used in the future, we can replace it
        if (j == pages.size()) {
            return i;
        }
    }
    // If all frames are used in the future, replace the farthest one
    return (pageToReplace == -1) ? 0 : pageToReplace;
}

// Function to implement the Optimal Page Replacement algorithm
void optimalPageReplacement(vector<int>& pages, int numFrames) {
    vector<int> frames;
    int miss = 0, hit=0;

    for (int i = 0; i < pages.size(); ++i) {
        if(find(frames.begin(), frames.end(),pages[i]) != frames.end()) {
            ++hit;
        }
        // If there is space in the frame list, add the page
        else if (frames.size() < numFrames) {
            frames.push_back(pages[i]);
            miss++;
        } 
        else {
            // If the page is not already present, replace a page
            int j = predict(pages, frames, i + 1);
            frames[j] = pages[i];
            frames.push_back(pages[i]);
            miss++;
        }
    }
    cout << "No. of Hit: " << hit << endl;
    cout << "No. of Miss: " << miss << endl;
}

int main() {

    int n; cin>>n; //No. of pages
    vector<int> Pages(n);
    for(int i=0; i<n; ++i) cin>>Pages[i];

    int numFrames; //No. of frames
    cin>>numFrames;

    optimalPageReplacement(Pages, numFrames);

    return 0;
}

//input
// 13 
// 7 0 1 2 0 3 0 4 2 3 0 3 2
// 4
// Output
// No. of Hit: 7
// No. of Miss: 6