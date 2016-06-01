#include "Player.h"

#include "GameTime.h"
#include "BackgroundGrid.h"
#include <cmath>
#include <cstdio>
#include <string>
#include <fstream>

Player::Player(){
_startMS = GameTime::GetTimeMS();
_name = "Anon";
_line = 0;
_piece = 0;
_dif = 0;
}

Player::~Player(){

}

void Player::Update(){
_line = BackgroundGrid::Instance()->GetClearedLines();
_piece = BackgroundGrid::Instance()->GetPieces();
_dif = GameTime::GetTimeMS() - _startMS;
}

void Player::Draw(){
//needs to be replaced with SDL output
std::cout<<"line:\n"<<_line<<"\n";
std::cout<<"piece:\n"<<_piece<<"\n";
std::cout<<"line/min:\n"<<(float)( (_line*60000)/_dif )<<"\n";
std::cout<<"piece/sec:\n"<<(float)( (_piece*1000)/_dif )<<"\n";
std::cout<<"time:\n"<<floor(_dif/60000)<<":"<<floor(_dif/1000) - 60*floor(_dif/60000)<<"."<<_dif - 1000*(floor(_dif/1000) - 60*floor(_dif/60000))<<"\n";

}

void Player::SetName(std::string& name)
{
    _name = name;
}

void Player::SetStart(unsigned int timeMS)
{
    _startMS = timeMS;
}

unsigned int Player::GetTime(){
    return GameTime::GetTimeMS()-_startMS;
}

unsigned int Player::GetPiece(){
    return _piece;
}

unsigned int Player::GetLine(){
    return _line;
}

std::string Player::GetName(){
    return _name;
}
unsigned int Player::GetStart(){
    return _startMS;
}
void Player::SaveScore(){

std::ofstream highscores;
highscores.open("Highscores.txt",std::fstream::app);
highscores<<_name<<":\n"<<"lines:"<<_line<<" pieces:"<<_piece<<" time:"<<floor(_dif/60000)<<":"<<floor(_dif/1000) - 60*floor(_dif/60000)<<"."<<_dif - 1000*(floor(_dif/1000) - 60*floor(_dif/60000))<<"\n";
highscores.close();
}
