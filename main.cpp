#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void insert_attribute();                                // Function prototypes
void update_attribute();
void delete_attribute();
void search_attribute();
void sort_attributes();
void display_products();

vector<vector<string>> matrix;                          // Declare a global 2D vector

int main()
{
    string line;                                        // String for storing a single line in the text file
    ifstream fin;                                       // Object for reading from and writing to files
    string attribute;                                   // String for temporarily storing an attribute

    int j = 0;

    fin.open("product_data.txt");                       // Open the text file

    while (getline(fin, line)) {    //

        vector<string> hello = {};                      // Initialize an empty string vector

        matrix.push_back(hello);                        // Push the empty string vector to the matrix

        for (int i = 0; i < line.length(); i++) {

            if (line[i] == ',') {                       // Check for comma seperating each attribute
                matrix[j].push_back(attribute);         // Push the complete attribute to the vector indexed by j
                attribute.clear();
            }
            else {
                attribute += line[i];                   // Concatenate the attribute with the character indexed by i
            }
        }

        matrix[j].push_back(attribute);                 // Push the last complete attribute to the vector
        attribute.clear();

        j++;
    }

    fin.close();                                        // Close the currently open text file

    int user_option;

    cout << "(1) Insert" << '\n';
    cout << "(2) Update" << '\n';
    cout << "(3) Delete" << '\n';
    cout << "(4) Search" << '\n';
    cout << "(5) Sort" << '\n';
    cout << "(6) Display Products" << '\n';
    cout << "Please select an option: ";

    cin >> user_option;

    switch (user_option) {
        case 1:
            insert_attribute();
        case 2:
            update_attribute();
        case 3:
            delete_attribute();
        case 4:
            search_attribute();
        case 5:
            sort_attributes();
        case 6:
            display_products();

    }
    return 0;
}

void insert_attribute() {


}

void update_attribute() {


}

void delete_attribute() {

}


void search_attribute() {

}

void sort_attributes() {

}


void display_products() {


}
