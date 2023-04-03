#include <iostream>

using namespace std;

/**
 * @brief Counts round score of second player based on the
 *        real meaning of input (Task 2).
 * 
 * @param a first player's choice
 * @param b desired game result
 * @return int - round score count
 */
int countRoundScore(char a, char b){
    int round_score = 0;

    // Assigning score based on desired game result
    if(b == 'Y'){ // Draw
        round_score += 3;
    }
    else if(b == 'Z'){ // Second player needs to win
        round_score += 6;
    }
    // Else first player wins, so second player's score doesn't change

    // Second player needs to choose rock
    if((a == 'A' && b == 'Y') || ((a == 'B' && b == 'X') || ((a == 'C' && b == 'Z')))){
        round_score += 1; 
    }
    // Second player needs to choose paper
    else if((a == 'A' && b == 'Z') || ((a == 'B' && b == 'Y') || ((a == 'C' && b == 'X')))){
        round_score += 2;
    }
    // Second player needs to choose scissors
    else if((a == 'A' && b == 'X') || ((a == 'B' && b == 'Z') || ((a == 'C' && b == 'Y')))){
        round_score += 3;
    }

    return round_score;
}

/**
 * @brief Counts total score from standard input.
 * 
 * @return int - total score count
 */
int countTotalScore(){
    int total_score = 0;
    string input_line;
    char oponents_choice, my_choice;

    while(getline(cin, input_line)){
        oponents_choice = input_line[0];
        my_choice = input_line[2];

        total_score += countRoundScore(oponents_choice, my_choice);
    }

    return total_score;
}


int main(){
    int total_score = countTotalScore();
    cout << "Total score (Task 2): " << total_score << "\n";
}
