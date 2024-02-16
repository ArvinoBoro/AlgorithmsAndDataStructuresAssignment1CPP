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
void delete_attribute();
void search_attribute();
void sort_attributes();
void display_products();
void write_to_file();

vector<vector<string>> matrix;                          // Declare a global 2D vector


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

    int user_option;

    cout << "(1) Insert" << '\n';
    cout << "(2) Update" << '\n';
    cout << "(3) Delete" << '\n';
    cout << "(4) Search" << '\n';
    cout << "(5) Sort" << '\n';
    cout << "(6) Display Products" << '\n';
    cout << "(7) Write to text file" << '\n';
    cout << "Please select an option: ";

    cin >> user_option;

    switch (user_option) {
        case 1:
            insert_product();
            display_products();
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
        case 7:
            write_to_file();

    }
    return 0;
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

void delete_attribute() {

    int position;

    cout << "Enter the position of the product: ";
    cin >> position;

    matrix.erase(matrix.begin() + position - 1);

}


void search_attribute() {

    int search_term;
    int result_count = 0;
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

    if (is_sorted) {

        int mid = floor((matrix.size() + 1) / 2 )

        if ()
    }

    } else {

        for (int i = 0; i < matrix.size(); i++) {

        if (toLowercase( matrix[i][search_term - 1] ) == toLowercase(content)  ) {

            result_count++;
            cout << "Search result " << result_count << ":\n";
            cout << matrix[i][0] << " ";
            cout << matrix[i][1] << " ";
            cout << matrix[i][2] << " ";
            cout << matrix[i][3] << "\n\n";

        }

    }

}

void sort_attributes() {

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
        cout << '\n';
    }

}


void write_to_file() {


}
