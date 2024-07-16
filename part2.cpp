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
        int translate(int d, char axis){
            cout << "translating point by " << d << " in " << axis << " axis...\n";
            switch (axis){
                case 'x':
                    this->x = this->x + d;
                    this->display();
                    return 0;
                    break;
                case 'y':
                    this->y = this->y + d;
                    this->display();
                    return 0;
                    break;
                case 'z':
                    this->z = this->z + d;
                    this->display();
                    return 0;
                    break;
                default:
                    cout << "point cannot be translated!\n";
                    return -1;
                    break;
            }
        }
    
        void display(){
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
        Triangle(Point* vertex_1, Point* vertex_2, Point* vertex_3){
            this->vertex_1 = vertex_1;
            this->vertex_2 = vertex_2;
            this->vertex_3 = vertex_3;
        }
        //default constructor
        Triangle(){
            this->vertex_1 = nullptr;
            this->vertex_2 = nullptr;
            this->vertex_3 = nullptr;
        }
        //destructor
        ~Triangle(){
            cout << "Triangle destructor executed\n";
        }
        //methods
        void displayPoints(){
            cout << "displaying points...\n";
            if (this->vertex_1 == nullptr || this->vertex_2 == nullptr || this->vertex_3 == nullptr){
                cout << "one or more vertex has null point values\n";
            } else {
                cout << "x1: " << this->vertex_1->getX() << " y1: " << this->vertex_1->getY()<< " z1: " << this->vertex_1->getZ() << "\n"; 
                cout << "x2: " << this->vertex_2->getX() << " y2: " << this->vertex_2->getY()<< " z2: " << this->vertex_2->getZ() << "\n"; 
                cout << "x3: " << this->vertex_3->getX() << " y3: " << this->vertex_3->getY()<< " z3: " << this->vertex_3->getZ() << "\n"; 
            }        
        }
        void translate(int d, char axis){
            cout << "translating triangle coordinates by " << d << " in the " << axis << " axis...\n";
            if (this->vertex_1 == nullptr || this->vertex_2 == nullptr || this->vertex_3 == nullptr){
                cout << "cannot translate! one or more vertex has null point values\n";
            } else {
                this->vertex_1->translate(d,axis);
                this->vertex_2->translate(d,axis);
                this->vertex_3->translate(d,axis);
            }
        }
        double calcArea(){

             double area = 0;
            cout << "calculating area...\n";

            if (this->vertex_1 == nullptr || this->vertex_2 == nullptr || this->vertex_3 == nullptr){
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
};

class Driver{
    public:
    static int main(){
        cout << "\n ***Point***\n";
        Point point1(3,2,3);
        point1.display();
        point1.setY(5);
        point1.display();
        cout << "return result of translation : " << point1.translate(5.5,'x') << "\n";

        Point point2(1,2,3);
        Point point3(9,8,7);

        cout << "\n ***Triangle***\n";

        //Triangle triangle;
        Triangle triangle(&point1, &point2, &point3);
        if (menuOption() == 1){
            triangle.displayPoints();
        } else {
            cout << "triangle coordinates not displayed\n";
        }
        triangle.translate(1,'x');
        triangle.displayPoints();
        triangle.calcArea();


        return 0;
    }

    static int menuOption(){
        int response;
        cout << "press 1 to display triangle coordinates on the screen. else press any other key\n";
        cin >> response;
        switch (response) {
            case 1:
                return 1;
                break;
            default:
                return 0;
                break;
        }
    }
};

int main() {
    return Driver::main();
}