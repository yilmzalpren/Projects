
/*
YILMAZ ALPEREN
1306190030
DATE:24.05.2020
DEVELOPMENT ENVIRONMENT: VISIUAL STUDIO 2019

IU-C COMPUTER E.
PROJECT SUBJECT:
----> We have to simulate a laboratory experiment as a life game.

*/
#include <iostream>			// this lib for input and output stream
#include <string>			// this lib for string and its functionalty
#include <vector>			// this lib for using vector as container.
#include <fstream>			// this lib for take inputfrom file and give output to file
#include <sstream>			// this lib for using Tokenizing in string 
#include <cmath>			// this lib just for "abs" function

std::ifstream inputFromFile;			// this object help us for take input to code 
std::ofstream outputToFile;				// this object help us for give information to output.txt
std::ofstream outputToTurns;			// this object help us for give information to turns.txt
std::string keeperFromFile;				// when we take input by using inputFromFile this object keep them.
int habitat;							//  habitat -------->  N x N
int turn_count;							// how many turns will be done 
//---------------------------------------------------------------------------------------------------------------
/*
														ENTITY
														/	  \
													   /       \
													  /         \
												   NORMAL       INFECTED
								INUM,NNORMAL,WILL_INFECTED  |   WILL_DEAD, WILL_RECOVERED
---------------------------------------------------------------------------------------------------------------------
													   ENTITY
													   /    \
													  /      \
													 /        \
												  DEAD        RECOVERED

*/
class Entity {
private:
	int coordinate[2];									// this information keep coordinate
	char gates[5];										// this information for Dna
	char specific1;										// i will provide inheretince by using these 2 specific char
	char specific2;
	int timerForIndividualProperties;				   // for example: for will_infected 3 times.
//*********************************************************************************************************************
public:
	void setCoordinate(int copy_coordinate[2]) {
		coordinate[0] = copy_coordinate[0];
		coordinate[1] = copy_coordinate[1];
	}
	int* getCoordinate() {
		return coordinate;
	}
	//---------------------------------------------------------------------------
	void setGates(char copy_gates[5]) {
		for (int i = 0; i < 5; ++i)gates[i] = copy_gates[i];
	}
	char* getGates() {
		return gates;
	}
	//-----------------------------------------------------------------------------
	void setSpecific1(char copy_specific1) {
		specific1 = copy_specific1;
	}
	char getSpecific1() {
		return specific1;
	}
	//---------------------------------------------------------------------------
	void setSpecific2(char copy_specific2) {
		specific2 = copy_specific2;
	}
	char getSpecific2() {
		return specific2;
	}
	//-------------------------------------------------------------------------
	void setTimer(int timer) {
		timerForIndividualProperties = timer;
	}
	int getTimer() {
		return timerForIndividualProperties;
	}
	void decraseTimer() {
		timerForIndividualProperties--;
	}
	//************************************************************************************************
	//                                    Here for "OPERATOR OVERLOADING"
	void operator+ () {	//-------------------------> normal to will_infected
		setSpecific2('w');
		setTimer(3 - 1);
	}
	void operator- () {//-------------------------> will_infected to will_dead or will_recovered
		int timer = 0;
		for (int i = 0; i < 5; ++i) {
			if (getGates()[i] == 'A' || getGates()[i] == 'B' || getGates()[i] == 'C' || getGates()[i] == 'D') {
				timer++;
			}
		}
		if (timer >= 3) {//-------> will_dead
			setSpecific1('I');
			setSpecific2('d');
			setTimer(14 - 1);
		}
		else {//-----------------> will_recovered
			setSpecific1('I');
			setSpecific2('r');
			setTimer(30 - 1);
		}

	}

	void operator-- () {//--------------------------------------->will_dead to dead
		setSpecific1('I');
		setSpecific2('s');
		setTimer(5 - 1);
	}

	void operator++ () {//--------------------------------------> will_recovered to recovered
		setSpecific1('R');
		setSpecific2(' ');
		setTimer(0);
	}

	void operator* () {//----------------------------------------> dead to really dead
		setSpecific1('D');
		setSpecific2(' ');
		setTimer(0);

	}


};
//********************************************************************************************************************************

void firstDefineWhatEntity(std::string str);
void createEntity(std::string strGates, std::string strCoordinate, int choose);
void getTurn(std::string str);
void assignTurn(std::string str, int n);
std::vector <Entity> Upcasting;				// this vector used for keep to Entity object
//*******************************************************************************************************************************
int main() {
	inputFromFile.open("input.txt");
	if (!inputFromFile.is_open()) std::cout << "Error for accessing inpu.txt" << std::endl;
	else {
		for (int i = 0; i < 2; ++i)inputFromFile >> keeperFromFile;
		habitat = std::stoi(keeperFromFile);
		for (int i = 0; i < 2; ++i) inputFromFile >> keeperFromFile;
		turn_count = std::stoi(keeperFromFile);
		inputFromFile.ignore(256, '\n');
		std::getline(inputFromFile, keeperFromFile);
		while (keeperFromFile.at(0) == 'e') {
			firstDefineWhatEntity(keeperFromFile);
			std::getline(inputFromFile, keeperFromFile);
		}
		getTurn(keeperFromFile);
		outputToTurns.open("TURNS.txt");
		outputToTurns.close();
		for (int Analoop = 2; Analoop <= turn_count; ++Analoop) {
			for (int i = 0; i < Upcasting.size(); ++i) {
				if ((Upcasting[i].getSpecific1() == 'N') && (Upcasting[i].getSpecific2() == 'w')) {
					if (Upcasting[i].getTimer() > 0) Upcasting[i].decraseTimer();
					else - (Upcasting[i]);
				}
				else if ((Upcasting[i].getSpecific1() == 'I') && (Upcasting[i].getSpecific2() == 'd')) {
					if (Upcasting[i].getTimer() > 0) Upcasting[i].decraseTimer();
					else --(Upcasting[i]);
				}
				else if (Upcasting[i].getSpecific1() == 'I' && (Upcasting[i].getSpecific2() == 'r')) {
					if (Upcasting[i].getTimer() > 0) Upcasting[i].decraseTimer();
					else ++(Upcasting[i]);
				}
				else if ((Upcasting[i].getSpecific1() == 'I' && (Upcasting[i].getSpecific2() == 's'))) {
					if (Upcasting[i].getTimer() > 0) Upcasting[i].decraseTimer();
					else *(Upcasting[i]);
				}

			}
			//-----------------------------------------------------------------------------------------------------------
			for (int i = 0; i < Upcasting.size(); ++i) {
				if (Upcasting[i].getSpecific1() == 'I') {
					for (int j = 0; j < Upcasting.size(); ++j) {
						if (Upcasting[j].getSpecific2() == 'n' && (Upcasting[j].getSpecific2() != 'w')) {
							if (abs(Upcasting[i].getCoordinate()[0] - (Upcasting[j].getCoordinate()[0])) <= 3 && abs(Upcasting[i].getCoordinate()[1] - (Upcasting[j].getCoordinate()[1])) <= 3) {
								+(Upcasting[j]);
							}
						}
					}
				}
			}
			//-------------------------------------------------------------------------------------------------------
			outputToTurns.open("TURNS.txt", std::ios::app);
			if (!outputToTurns.is_open()) std::cout << "Turns.txt can not be accessed";
			else {
				outputToTurns << "Turn " << Analoop - 1 << " : " << std::endl;
				for (int i = 0; i < habitat + 2; ++i) outputToTurns << '-';
				outputToTurns << std::endl;
				for (int i = 1; i <= habitat; ++i) {
					outputToTurns << '-';
					for (int j = 1; j <= habitat; ++j) {
						bool checkerForOutput = false;
						char keeperCharForOutput;
						for (int timer_vector = 0; timer_vector < Upcasting.size(); ++timer_vector) {
							if (Upcasting[timer_vector].getCoordinate()[0] == i && Upcasting[timer_vector].getCoordinate()[1] == j) {
								checkerForOutput = true;
								if ((Upcasting[timer_vector].getSpecific1() == 'N') || Upcasting[timer_vector].getSpecific1() == 'R') keeperCharForOutput = 'O';
								else if ((Upcasting[timer_vector].getSpecific1() == 'I') && !(Upcasting[timer_vector].getSpecific2() == 's')) keeperCharForOutput = 'X';
								else if (Upcasting[timer_vector].getSpecific2() == 's') keeperCharForOutput = 'D';
								else keeperCharForOutput = ' ';
							}
						}
						if (checkerForOutput) outputToTurns << keeperCharForOutput;
						else outputToTurns << ' ';
					}
					outputToTurns << '-';
					outputToTurns << std::endl;
				}
			}
			for (int i = 0; i < habitat + 2; ++i) outputToTurns << '-';
			outputToTurns << std::endl;
			outputToTurns.close();

			//-------------------------------------------------------------------------------------------------------
			std::getline(inputFromFile, keeperFromFile);
			getTurn(keeperFromFile);


		}
		//------------------------------------------------------------------------------------------------
		outputToTurns.open("TURNS.txt", std::ios::app);
		if (!outputToTurns.is_open()) std::cout << "Turns.txt can not be accessed";
		else {
			outputToTurns << "Turn " << turn_count << " : " << std::endl;
			for (int i = 0; i < habitat + 2; ++i) outputToTurns << '-';
			outputToTurns << std::endl;
			for (int i = 1; i <= habitat; ++i) {
				outputToTurns << '-';
				for (int j = 1; j <= habitat; ++j) {
					bool checkerForOutput = false;
					char keeperCharForOutput;
					for (int timer_vector = 0; timer_vector < Upcasting.size(); ++timer_vector) {
						if (Upcasting[timer_vector].getCoordinate()[0] == i && Upcasting[timer_vector].getCoordinate()[1] == j) {
							checkerForOutput = true;
							if ((Upcasting[timer_vector].getSpecific1() == 'N') || Upcasting[timer_vector].getSpecific1() == 'R') keeperCharForOutput = 'O';
							else if ((Upcasting[timer_vector].getSpecific1() == 'I') && !(Upcasting[timer_vector].getSpecific2() == 's')) keeperCharForOutput = 'X';
							else if (Upcasting[timer_vector].getSpecific2() == 's') keeperCharForOutput = 'D';
							else keeperCharForOutput = ' ';
						}
					}
					if (checkerForOutput) outputToTurns << keeperCharForOutput;
					else outputToTurns << ' ';
				}
				outputToTurns << '-';
				outputToTurns << std::endl;
			}
		}
		for (int i = 0; i < habitat + 2; ++i) outputToTurns << '-';
		outputToTurns << std::endl;
		outputToTurns.close();

	}
	//----------------------------------------------------------------------------------------------------
	inputFromFile.close();
	outputToFile.open("output.txt");
	if (!outputToFile.is_open()) std::cout << "Output.txt can not be created by this program" << std::endl;
	else {
		int FinalNormal = 0;
		int FinalInfected = 0;
		int FinalDead = 0;
		int FinalRecovered = 0;
		for (int i = 0; i < Upcasting.size(); ++i) {
			if (Upcasting[i].getSpecific1() == 'N') FinalNormal++;
			else if (Upcasting[i].getSpecific1() == 'I') FinalInfected++;
			else if ((Upcasting[i].getSpecific2() == 's') || (Upcasting[i].getSpecific1() == 'D')) FinalDead++;
			else if (Upcasting[i].getSpecific1() == 'R') FinalRecovered++;
		}
		outputToFile << "Normal      :" << FinalNormal << '\n';
		outputToFile << "Infected    :" << FinalInfected << '\n';
		outputToFile << "Dead        :" << FinalDead << '\n';
		outputToFile << "Recovered   :" << FinalRecovered << '\n';
		for (int i = 0; i < Upcasting.size(); ++i) {
			outputToFile << "entity " << i + 1 << " " << Upcasting[i].getCoordinate()[0] << "x" << Upcasting[i].getCoordinate()[1];
			if (Upcasting[i].getSpecific1() == 'N') outputToFile << " normal" << '\n';
			else if (Upcasting[i].getSpecific1() == 'I') outputToFile << " infected" << '\n';
			else if ((Upcasting[i].getSpecific2() == 's') || (Upcasting[i].getSpecific1() == 'D')) outputToFile << " dead" << '\n';
			else if (Upcasting[i].getSpecific1() == 'R') outputToFile << " recovered" << '\n';
		}
	}
	outputToFile.close();


	return 0;
}

void firstDefineWhatEntity(std::string str) {
	std::vector <std::string> keeperWord;
	std::stringstream checker(str);
	std::string tempForWord;
	while (std::getline(checker, tempForWord, ' ')) {
		keeperWord.push_back(tempForWord);
	}
	if (keeperWord.size() == 5) {
		int timer = 0;
		for (int i = 0; i < 5; ++i) {
			if (keeperWord[2].at(i) == 'A' || keeperWord[2].at(i) == 'B' || keeperWord[2].at(i) == 'C' || keeperWord[2].at(i) == 'D') {
				timer++;
			}
		}
		if (timer >= 3) { // this is will-dead
			createEntity(keeperWord[2], keeperWord[3], 3);
		}
		else {// this is will_recovered
			createEntity(keeperWord[2], keeperWord[3], 4);
		}
	}
	else {
		int timer = 0;
		for (int i = 0; i < 5; ++i) {
			if (keeperWord[2].at(i) == 'A' || keeperWord[2].at(i) == 'B') timer++;
		}
		if (timer == 0) { // this is inum
			createEntity(keeperWord[2], keeperWord[3], 1);
		}
		else {			// this is nnormal
			createEntity(keeperWord[2], keeperWord[3], 2);
		}

	}
}

void createEntity(std::string strGates, std::string strCoordinate, int choose) {
	char tempForGates[5];
	int tempForCoordinate[2];
	for (int i = 0; i < 5; ++i) {
		tempForGates[i] = strGates.at(i);
	}
	std::vector <std::string> tokensForWord; // this is for using Tokenizing in string
	std::stringstream checker(strCoordinate);
	std::string temp;
	int xTimer = 0;
	for (int i = 0; i < strCoordinate.size(); ++i) {
		if (strCoordinate.at(i) == 'x') xTimer++;
	}

	if (xTimer > 0) {
		while (std::getline(checker, temp, 'x')) {
			tokensForWord.push_back(temp);
		}
	}
	else {
		while (std::getline(checker, temp, 'X')) {
			tokensForWord.push_back(temp);
		}
	}
	tempForCoordinate[0] = std::stoi(tokensForWord[0]);
	tempForCoordinate[1] = std::stoi(tokensForWord[1]);

	if (choose == 1) {
		Entity tempForInum;
		tempForInum.setCoordinate(tempForCoordinate);
		tempForInum.setGates(tempForGates);
		tempForInum.setSpecific1('N');
		tempForInum.setSpecific2('i');
		tempForInum.setTimer(0);
		Upcasting.push_back(tempForInum);
	}
	else if (choose == 2) {
		Entity tempForNnormal;
		tempForNnormal.setCoordinate(tempForCoordinate);
		tempForNnormal.setGates(tempForGates);
		tempForNnormal.setSpecific1('N');
		tempForNnormal.setSpecific2('n');
		tempForNnormal.setTimer(0);
		Upcasting.push_back(tempForNnormal);

	}
	else if (choose == 3) {
		Entity tempForWill_dead;
		tempForWill_dead.setCoordinate(tempForCoordinate);
		tempForWill_dead.setGates(tempForGates);
		tempForWill_dead.setSpecific1('I');
		tempForWill_dead.setSpecific2('d');
		tempForWill_dead.setTimer(14 - 1);
		Upcasting.push_back(tempForWill_dead);

	}
	else if (choose == 4) {
		Entity tempforWill_recovered;
		tempforWill_recovered.setCoordinate(tempForCoordinate);
		tempforWill_recovered.setGates(tempForGates);
		tempforWill_recovered.setSpecific1('I');
		tempforWill_recovered.setSpecific2('r');
		tempforWill_recovered.setTimer(30 - 1);
		Upcasting.push_back(tempforWill_recovered);
	}

}
void getTurn(std::string str) {
	std::vector <std::string > keeperWord;
	std::stringstream checker(str);
	std::string temp;
	while (std::getline(checker, temp, ' ')) {
		keeperWord.push_back(temp);
	}
	for (int i = 2; i < keeperWord.size(); ++i) {
		assignTurn(keeperWord.at(i), (i - 2));
	}
}

void assignTurn(std::string str, int n) {
	std::vector <std::string > tokenForWord;
	std::stringstream checker(str);
	std::string temp;
	int Xtimer = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str.at(i) == 'x') Xtimer++;
	}
	if (Xtimer > 0) {
		while (std::getline(checker, temp, 'x')) {
			tokenForWord.push_back(temp);
		}
	}
	else {
		while (std::getline(checker, temp, 'X')) {
			tokenForWord.push_back(temp);
		}
	}
	int coordinate[2];
	coordinate[0] = std::stoi(tokenForWord[0]);
	coordinate[1] = std::stoi(tokenForWord[1]);
	if (!(Upcasting[n].getSpecific1() == 'D' || Upcasting[n].getSpecific2() == 's'))
		Upcasting.at(n).setCoordinate(coordinate);

}
