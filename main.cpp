#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
    int data;
public:
    Test():data{0} {
        cout<< "\tTest Constructor (" << data << ")" << endl;
    }
    Test(int data):data{data} {
        cout<< "\tTest Constructor (" << data << ")" << endl;
    } 
    int get_data() const {return data;}
    
    ~Test() {cout<< "\tTest Destructor (" << data << ")" << endl;}
};

// Function Prototypes
unique_ptr <vector <shared_ptr <Test>>> make(); // can also write auto make();
                                                // this way the compiler figures out the return type
void fill (vector <shared_ptr<Test>> &vec, int num);
void display (const vector <shared_ptr<Test>> &vec);

int main() {
    
    unique_ptr <vector <shared_ptr <Test>>> vec_ptr;
    
    vec_ptr = make();
    
    int num {0};
    cout << "How many data points do you want to enter? ";
    cin >> num;
    
    fill (*vec_ptr,num);
    display (*vec_ptr);
    
    return 0;
}

unique_ptr <vector <shared_ptr <Test>>> make() {
    vector <shared_ptr <Test>> v;
    unique_ptr <vector <shared_ptr <Test>>> vec_ptr = make_unique <vector <shared_ptr <Test>>> (v);
    return vec_ptr;
    
    // can also do: return make_unique <vector <shared_ptr <Test>>> ();
    // () represents constructor for the vector
}

void fill (vector <shared_ptr<Test>> &vec, int num) {
    int temp {0};
    for (int i {1}; i <= num; ++i) {
        cout << "Enter data point [" << i << "]:";
        cin >> temp;
        
        shared_ptr<Test> p1 = make_shared <Test> (temp);
        vec.push_back(p1);
        // In one step can do: return vec.push_back (make_shared <Test> (temp));
    }
}

void display (const vector <shared_ptr<Test>> &vec) {
    cout << "\nDisplaying Vector Data: " << endl << "==========================" << endl;
    for (const auto &v:vec) {
        cout << v -> get_data() << endl; // Can also use (*v).get_data()
    }
}