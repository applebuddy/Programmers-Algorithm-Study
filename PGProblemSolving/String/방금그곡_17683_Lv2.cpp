

// MARK: - 방금그곡_18693_Lv2

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct NowMusicInfo {
public:
    string name = "";
    int playingTime = 0;
    int order = 0;
    NowMusicInfo(string name, int playingTime, int order) {
        this->name = name;
        this->playingTime = playingTime;
        this->order = order;
    }
};

string justNowThatSong(string m, vector<string> musicinfos) {
    vector<NowMusicInfo> Ans;
    
    for(int i=0; i<musicinfos.size(); i++) {
        string musicinfo = musicinfos[i];
        int nowIdx = 0, dotCnt = 0;
        vector<string> SV;

        while(musicinfo.length() > 0) {
            if(musicinfo[nowIdx] == ',') {
                SV.push_back(musicinfo.substr(0,nowIdx));
                musicinfo = musicinfo.substr(nowIdx+1);
                dotCnt++;
                if(dotCnt >= 3){
                    SV.push_back(musicinfo);
                    break;
                }
                nowIdx = 0;
            } else {
                nowIdx++;
            }
        }
        
        vector<int> sTime = { stoi(SV[0].substr(0,2)), stoi(SV[0].substr(3,2)) };
        vector<int> eTime = { stoi(SV[1].substr(0,2)), stoi(SV[1].substr(3,2)) };
        vector<int> playTime = {0,0};
        if(eTime[1] < sTime[1]) {
            eTime[0]--;
            playTime[1] = eTime[1] + 60 - sTime[1];
        }
        else playTime[1] = eTime[1] - sTime[1];
        playTime[0] = eTime[0] - sTime[0];

        string mMelody = "";
        for(int j=0; j<m.length(); j++) {
            string subMelody = "";
            if(j+1 < m.length() && m[j+1] == '#') {
                subMelody += m[j];
                subMelody += m[j+1];
                mMelody += subMelody;
                j++;
            }
            else {
                subMelody += m[j];
                subMelody += '-';
                mMelody += subMelody;
            }
        }
        
        vector<string> songV;
        string melody = SV[3];
        string checkMelody = "";
        for(int j=0; j<melody.length(); j++) {
            string subMelody = "";
            if(j+1 < melody.length() && melody[j+1] == '#') {
                    subMelody += melody[j];
                    subMelody += melody[j+1];
                    checkMelody += subMelody;
                    songV.push_back(subMelody);
                    j++;
            }
            else {
                    subMelody += melody[j];
                    subMelody += '-';
                    checkMelody += subMelody;
                    songV.push_back(subMelody);
            }
        }
        
        string repeatSong = "";
        int playingTime = playTime[0]*60 + playTime[1];
        for(int j=0; j<playingTime/songV.size(); j++) repeatSong += checkMelody;
        
        for(int j=0; j<playingTime%songV.size(); j++) repeatSong += songV[j];

        if(repeatSong.find(mMelody) != string::npos) {
            int playingTime = playTime[0]*60 + playTime[1];
            Ans.push_back(NowMusicInfo(SV[2], playingTime, i+1));
        }
    }
    
    if(Ans.size()==0) return "(None)";
    else if(Ans.size()==1) return Ans[0].name;
    else {
        sort(Ans.begin(), Ans.end(), [](NowMusicInfo &a, NowMusicInfo &b) {
            return (a.playingTime > b.playingTime) || ((a.playingTime == b.playingTime) && (a.order < b.order));
        });
        return Ans[0].name;
    }
}
