#include <iostream>

using namespace std;

/**
 * @brief Counts round score of second player based on the
 *        Task 1 understanding of input meaning.
 * 
 * @param a first player's choice
 * @param b second player's choice
 * @return int - round score count
 */
int countRoundScore(char a, char b){
    int round_score = 0;

    // Assigning score based on second player's choice
    if(b == 'X'){
        round_score += 1;
    }
    else if(b == 'Y'){
        round_score += 2;
    }
    else if(b == 'Z'){
        round_score += 3;
    }

    // Both players chose same shape
    if((a == 'A' && b == 'X') || ((a == 'B' && b == 'Y') || ((a == 'C' && b == 'Z')))){
        round_score += 3; 
    }
    // Second player wins
    else if((a == 'A' && b == 'Y') || ((a == 'B' && b == 'Z') || ((a == 'C' && b == 'X')))){
        round_score += 6;
    }
    // Else first player wins, so second player's score doesn't change

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
    cout << "Total score (Task 1): " << total_score << "\n";
}
