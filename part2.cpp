//Sonia Rahal 40211893
//Parker Harris-Bytautas 40207549
#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        //attributes
        int x;
        int y;
        int z;
    public:
        //constructor

        Point() {
            this->x = 0;
            this->y = 0;
            this->z = 0; 
        }

        Point(int x, int y, int z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        //destructor
        ~Point(){
            cout << "Point destructor executed\n";
        }
        //methods
        int translate(int d, char axis) {

            cout << "translating point by " << d << " in " << axis << " axis...\n";

            if (typeid(d) != typeid(int))
                return -2;

            switch (axis) {

                case 'x':
                    this->x += d;
                    break;

                case 'y':
                    this->y +=+ d;
                    break;

                case 'z':
                    this->z += d;
                    break;

                default:
                    cout << "point cannot be translated!\n";
                    return -1;
                    break;
            }
            this->display();
            return 0;
        }
    
        void display() {
            cout << "displaying point...\n";
            cout <<  "x: " << this->getX() << " y: " << this->getY() << " z: " << this->getZ() << "\n";
        }
        //setters and getters
        void setX(int x){
            this->x = x;
        }
        void setY(int y){
            this->y = y;
        }
        void setZ(int z){
            this->z = z;
        }
        int getX(){
            return this->x;
        }
        int getY(){
            return this->y;
        }
        int getZ(){
            return this->z;
        }
};


class Triangle {
    private:
        //attributes
        Point* vertex_1;
        Point* vertex_2;
        Point* vertex_3;
    public:
        //constructor
        Triangle(Point* vertex_1, Point* vertex_2, Point* vertex_3) {
            this->vertex_1 = vertex_1;
            this->vertex_2 = vertex_2;
            this->vertex_3 = vertex_3;
        }
        //default constructor
        Triangle() {
            this->vertex_1 = nullptr;
            this->vertex_2 = nullptr;
            this->vertex_3 = nullptr;
        }
        //destructor
        ~Triangle() {
            cout << "Triangle destructor executed\n";
        }
        //methods
        void displayPoints() {
            cout << "displaying points...\n";
            if (this->vertex_1 == nullptr || this->vertex_2 == nullptr || this->vertex_3 == nullptr){
                cout << "one or more vertex has null point values\n";
            } else {
                cout << "x1: " << this->vertex_1->getX() << " y1: " << this->vertex_1->getY()<< " z1: " << this->vertex_1->getZ() << "\n"; 
                cout << "x2: " << this->vertex_2->getX() << " y2: " << this->vertex_2->getY()<< " z2: " << this->vertex_2->getZ() << "\n"; 
                cout << "x3: " << this->vertex_3->getX() << " y3: " << this->vertex_3->getY()<< " z3: " << this->vertex_3->getZ() << "\n"; 
            }        
        }
        void translate(int d, char axis) {
            cout << "translating triangle coordinates by " << d << " in the " << axis << " axis...\n";
            if (this->vertex_1 == nullptr || this->vertex_2 == nullptr || this->vertex_3 == nullptr){
                cout << "cannot translate! one or more vertex has null point values\n";
            } else {
                this->vertex_1->translate(d,axis);
                this->vertex_2->translate(d,axis);
                this->vertex_3->translate(d,axis);
            }
        }
        double calcArea() {

            double area = 0;
            cout << "calculating area...\n";

            if (this->vertex_1 == nullptr || this->vertex_2 == nullptr || this->vertex_3 == nullptr) {
                cout << "one or more vertices are null, cannot calculate area\n";
                return area;
            }

            int x1 = this->vertex_1->getX();
            int y1 = this->vertex_1->getY();
            int z1 = this->vertex_1->getZ();

            int x2 = this->vertex_2->getX();
            int y2 = this->vertex_2->getY();
            int z2 = this->vertex_2->getZ();

            int x3 = this->vertex_3->getX();
            int y3 = this->vertex_3->getY();
            int z3 = this->vertex_3->getZ();

            cout << "x1: " << x1 << "\n";
            cout << "y2-y3: " << y2-y3 << "\n";
            cout << "x2: " << x2 << "\n";
            cout << "y3-y1: " << y3-y1 << "\n";
            cout << "x3: " << x3 << "\n";
            cout << "y1-y2: " << y1-y2 << "\n";
            cout << "area: " << "0.5 * abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))\n";
            cout << "area: " << "0.5 * abs(" << x1 << " * " << y2-y3 << " + " << x2 << " * " << y3-y1 << " + " << x3 << " * " << y1-y2 << ")\n";
            cout << "area: " <<  "0.5 * abs(" << x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2) << ")\n";

            area = (0.5)*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));

            cout << "the area of the triangle is: " << area << "\n";
            
            return area;
        }


        double calcAreaTwo() {

            double area =  0.5 * sqrt(pow((vertex_2->getY() - vertex_1->getY())*(vertex_3->getZ() - vertex_1->getZ()) - (vertex_2->getZ() - vertex_1->getZ())*(vertex_3->getY() - vertex_1->getY()), 2) +
                                pow((vertex_2->getZ() - vertex_1->getZ())*(vertex_3->getX() - vertex_1->getX()) - (vertex_2->getX() - vertex_1->getX())*(vertex_3->getZ() - vertex_1->getZ()), 2) +
                                pow((vertex_2->getX() - vertex_1->getX())*(vertex_3->getY() - vertex_1->getY()) - (vertex_2->getY() - vertex_1->getY())*(vertex_3->getX() - vertex_1->getX()), 2));
            cout << "area is: " << area << "\n";
            return area;
        }
};

class Driver{
    public:
    static int main(){

        while (true) {

            if (menuOption() == 0) 
                return 0; 
                

            int myPoints[9];

            cout << "Enter the nine integers you would like to use for the triangle points..." << endl;

            for (int i = 0; i < 9; i++) {
                while (true) {
                    cout << "Enter integer number " << i + 1 << ": ";
                    cin >> myPoints[i];

                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore();
                        cout << "Invalid input. Please enter an integer." << endl;
                    } else {
                        break; 
                    }
                }
            }

            Point point1;
            Point point2;
            Point point3;

            point1.setX(myPoints[0]);
            point1.setY(myPoints[1]);
            point1.setZ(myPoints[2]);

            point2.setX(myPoints[3]);
            point2.setY(myPoints[4]);
            point2.setZ(myPoints[5]);

            point3.setX(myPoints[6]);
            point3.setY(myPoints[7]);
            point3.setZ(myPoints[8]);


            cout << "\n ***Triangle***\n";

            Triangle triangle(&point1, &point2, &point3);

            triangle.displayPoints();
            triangle.calcAreaTwo();

            
            string choice;
            while (true) {
            
                cout << "Would you like to translate the Triangle (y/n)?" << endl;
                cin >> choice;

                if (choice == "y" || choice == "Y") {
                    int d;
                    char axis;

                    cout << "Enter amount to translate by: ";
                    cin >> d;

                    cout << "Enter axis (x, y or z): ";
                    cin >> axis;

                    triangle.translate(d, axis);

                    triangle.displayPoints();
                    triangle.calcAreaTwo();
                }
                else
                    break;
  
            }

        }

        return 0;
       
    }



    static int menuOption(){
        
        while (true) {
            cout << "Triangle Program Menu \n";
            cout << "1. Calculate Triangle \n";
            cout << "2. Exit \n";

            int choice;
            cin >> choice;

            if ((typeid(choice) != typeid(int)) || choice != 1) 
                return 0;
            else
                return 1;

        }

    }
};

int main() {
    return Driver::main();
}