#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define INT_MAX_NUMBER_COUNT 10

class ElveInventory{
    private:
        int calories_sum;

    public:
        ElveInventory(vector<int> input_calories){
            calories_sum = 0;

            for(auto i : input_calories){
                calories_sum += i;
            }
        }

        int getCaloriesSum(){
            return calories_sum;
        }

};

/**
 * @brief Loads Elves inventories from stdin.
 * 
 * @param arr Vector, where Elves inventories will be loaded in.
 */
void loadElvesInventories(vector<ElveInventory>& arr){
    char a[INT_MAX_NUMBER_COUNT]; // C-type array of chars for processing of fgets function
    string input_line;
    vector<int> elve_calories;

    while(fgets(a, INT_MAX_NUMBER_COUNT, stdin)){
        input_line = a;

        if(input_line.size() > 1){
            elve_calories.push_back(stoi(input_line));
        }
        else{
            ElveInventory elve_to_add(elve_calories);
            arr.push_back(elve_to_add);
            elve_calories.clear();
        }
    }
}

/**
 * @brief Prints the number of Elve with most calories in inventory. Also prints the sum 
 *        of this Elve's inventory calories.
 * 
 * @param arr Vector of Elves inventories, where function will look.
 */
void printElveWithMostCalories(vector<ElveInventory>& arr){
    if(arr.size() == 0){
        cout << "No elve in input\n";
        return ;
    }

    int max_calories = arr.front().getCaloriesSum();
    int elve_index = 0;

    for(int i = 1; i < arr.size(); i++){
        if(arr[i].getCaloriesSum() > max_calories){
            max_calories = arr[i].getCaloriesSum();
            elve_index = i;
        }
    }

    cout << "Elve with most calories in inventory: " << elve_index << " (" << max_calories << ")\n";
}

int main(){
    vector<ElveInventory> elves_inventories;

    loadElvesInventories(elves_inventories);
    printElveWithMostCalories(elves_inventories);

}