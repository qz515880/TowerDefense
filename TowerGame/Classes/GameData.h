#ifndef _GAMEDATA_H_
#define _GAMEDATA_H_

class GAMEDATA{
public:
	static GAMEDATA* getInstance();

	void setGameGold(int gold);
	int getGameScore();

	void setSoundState(bool state);
	bool getSoundState();
	void setMusicState(bool state);
	bool getMusicState();
private:
	GAMEDATA();
	void init();
	static GAMEDATA* _instance;
	int gameGold;
};
#endif