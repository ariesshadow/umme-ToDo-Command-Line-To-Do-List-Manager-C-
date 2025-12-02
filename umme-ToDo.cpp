#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class TodoItem{
    private:
    int id;
    string description;
    bool completed;

    public:
    TodoItem() : id(0) , description ("") , completed (false) {}
    ~TodoItem() {}
    
    bool create(string new_description){
        id = rand() % 100+1;  //generates random id's from 1-100
        description = new_description;
        return true;
    }

    //these getter functions provide read-only access
    int getID(){
        return id;
    }

    string getDescription(){
        return description;
    }

    bool isCompleted(){
        return completed;
    }

    void setCompleted(bool val){
        completed = val;
    }
    void setDescription(string new_description){
        description = new_description;
    }

};

int main(){
    char input_option;
    int input_id;
    string input_description;
    string version = "umme version";
    list<TodoItem> todoItems;   //todoItems - list storing all the to-do items
    list<TodoItem> :: iterator it;  //it - iterator used to loop through list

    srand(time(NULL)); //to generate different random id everytime

    todoItems.clear();  //Just ensures it's empty

    while(1){
        system("cls"); //clear console
        cout << "ToDo List Maker -" << version << endl;
        cout << endl << endl;

        for(it = todoItems.begin(); it != todoItems.end(); it++) //Loop from first node to last of the linked list 
        {
            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getID() << " | " << it->getDescription() << " | " << completed << endl;
        }

        if(todoItems.empty()){
            cout << "Add your first to do !" << endl;
        }
        cout << endl << endl;

        cout << "[a]dd a new To Do" << endl;
        cout << "[c]omplete a To Do" << endl;
        cout << "[d]elete a To Do" << endl;
        cout << "[u]pdate a To Do" << endl;
        cout << "[q]uit" << endl;

        cout << endl << "Choice: ";
        cin >> input_option;

        if(input_option == 'a'){
            cout << "Add a new description: ";
            cin.ignore();  //clears leftover newline
            getline(cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);  //Creates a to-do and pushes into list
        }

        else if(input_option == 'c'){
            cout << "Enter id to mark completed: ";
            cin >> input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++) //Loops through list to find matching ID 
            {
                if(input_id == it->getID()){
                    it -> setCompleted(true);
                    break;
                }
            }
        }

        else if(input_option == 'd'){
            cout << "Enter ID to delete the To Do: ";
            cin >> input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++){
                    if(input_id == it->getID()){
                        todoItems.erase(it); //When matching ID is found → erase that node
                        break;
                    }
            }
        }

        else if (input_option == 'u') {
            cout << "Enter ID to update: ";
            cin >> input_id;
            cin.ignore();

            for(it = todoItems.begin(); it != todoItems.end(); it++){
                if(input_id == it->getID()){
                    cout << "New description: ";
                    getline(cin, input_description);
                    it->setDescription(input_description);
                    break;
                }
            }
        }

        else if(input_option == 'q'){
            cout << "Have a great day now ! " << endl;
            break;
        }

    }

    return 0;
}