#include <iostream>

using namespace std;

class Point3d {
private:
	int m_x;
	int m_y;
	int m_z;

public:
	void setValues(int x, int y, int z){
		m_x = x;
		m_y = y;
		m_z = z;

	}

	void print(){
		cout << "x: " << m_x << endl;
		cout << "y: " << m_y << endl;
		cout << "z: " << m_z << endl;
	}
};

int main(){
	Point3d point;
	point.setValues(1,2,3);

	point.print();

	return 0;
}