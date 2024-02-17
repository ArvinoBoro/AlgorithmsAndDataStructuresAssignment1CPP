#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

void insert_product();                                // Function prototypes
void update_attribute();
void delete_product();
void search_attribute();
void sort_products();
void display_products();
void write_to_file();

vector<vector<string>> matrix;                          // Declare a global 2D vector
bool sorted = false;


std::string toLowercase(const std::string& str) {
    std::string result = str; // Make a copy of the original string

    // Convert each character to lowercase
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return result;
}

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
                i++;
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


    while (true) {

        int user_option;

        cout << "(1) Insert" << '\n';
        cout << "(2) Update" << '\n';
        cout << "(3) Delete" << '\n';
        cout << "(4) Search" << '\n';
        cout << "(5) Sort" << '\n';
        cout << "(6) Display Products" << '\n';
        cout << "(7) Write to text file" << '\n';
        cout << "(8) Exit" << '\n';
        cout << "Please select an option: ";

        cin >> user_option;

        switch (user_option) {
            case 1:
                insert_product();
                break;
            case 2:
                update_attribute();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                search_attribute();
                break;
            case 5:
                sort_products();
                break;
            case 6:
                display_products();
                break;
            case 7:
                write_to_file();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid option. Please try again. \n";
                break;
        }
    }
}

void insert_product() {

    int position;
    vector<string> new_product(5);

    cout << '\n' << "Select the position: ";
    cin >> position;
    cin.ignore();
    cout << '\n';

    cout << "ID: ";
    getline(cin, new_product[0]);
    cout << '\n';

    cout << "Name: ";
    getline(cin, new_product[1]);
    cout << '\n';

    cout << "Price: ";
    getline(cin, new_product[2]);
    cout << '\n';

    cout << "Category: ";
    getline(cin, new_product[3]);
    cout << '\n';

    matrix.insert(matrix.begin() + position - 1, new_product);
}

void update_attribute() {

    int position, option;

    cout << "Enter the position of the product: ";
    cin >> position;

    cout << "(1) ID\n";
    cout << "(2) Name\n";
    cout << "(3) Price\n";
    cout << "(4) Category\n";

    cout << "What would you like to edit?: ";
    cin >> option;
    cin.ignore();

    std::cout << "Enter the new attribute: ";

    getline(cin, matrix[position-1][option-1]);

}

void delete_product() {

    int position;

    cout << "Enter the position of the product: ";
    cin >> position;

    matrix.erase(matrix.begin() + position - 1);
}


void search_attribute() {

    int search_term;
    int result_count = 0;
    vector<int> matched_product_indices;
    string content;

    cout << "(1) ID\n";
    cout << "(2) Name\n";
    cout << "(3) Price\n";
    cout << "(4) Category\n";

    cout << "Enter the search term: ";
    cin >> search_term;
    cout << '\n';

    cout << "Enter its content: ";
    cin >> content;
    cout << '\n';

    if (sorted && (search_term == 3 )) {

        int i = 1;
        int j = matrix.size();
        int k = 0;
        float price = stof(content);

        while (i < j) {

            int mid = floor((i + j) / 2 );

            if (price > stof(matrix[mid-1][2]))
                i = mid + 1;

            else
                j = mid;
        }

        if (price == stof(matrix[i-1][2])) {

            for (int k = 0; price == stoi(matrix[i + k][2]); k++)

                matched_product_indices.push_back(i+k);


            for (int l = -2; price == stof(matrix[i + l][2]); l--)

                matched_product_indices.push_back(i+l);


            for (int m = 0; m < matched_product_indices.size(); m++) {

                cout << matrix[matched_product_indices[m]][0] << " ";
                cout << matrix[matched_product_indices[m]][1] << " ";
                cout << matrix[matched_product_indices[m]][2] << " ";
                cout << matrix[matched_product_indices[m]][3] << "\n\n";
            }

        } else {

            cout << "No results found.\n\n";
        }

    } else {

        for (int i = 0; i < matrix.size(); i++) {

            if (toLowercase( matrix[i][search_term - 1] ) == toLowercase(content)  ) {

                result_count++;
                cout << matrix[i][0] << " ";
                cout << matrix[i][1] << " ";
                cout << matrix[i][2] << " ";
                cout << matrix[i][3] << "\n\n";

            }
        }

        if (result_count == 0)
            cout << "No results found.\n\n";
    }

}


void sort_products() {

    for (int i = 0; i < matrix.size()-1; i++) {
        for (int j = 0; j < matrix.size()-i-1; j++) {

            if (stoi(matrix[j][2]) > stoi(matrix[j+1][2])) {

                vector<string> temp = matrix[j];
                matrix[j] = matrix[j+1];
                matrix[j + 1] = temp;
            }
        }
    }

    sorted = true;
}


void display_products() {

    for (int i = 0; i < matrix.size(); i++) {

        cout << "(";

        if (i < 9)
            cout << "0";

        cout << i+1 << ") ";

        for (int j = 0; j < matrix[j].size(); j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }

}


void write_to_file() {


}
