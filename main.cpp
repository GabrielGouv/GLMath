#include <iostream>
#include "math.cpp"

int main() {

//    Vector3D v3 = Vector3D(1.0, 0.0, 0.0);
//    Vector3D v31 = Vector3D(1.0, 3.0, 1.0);
//
//    float mag = Magnitude(v3);
//
//    Vector3D vN = Normalize(v3);
//
//    float vNMag = Magnitude(vN);
//
//    v3 -= v31;
//    Vector3D sub = v3 - v31;



//    std::cout << sub.x << ", " << sub.y << ", " << sub.z << std::endl;
//    std::cout << v3.x << ", " << v3.y << ", " << v3.z << std::endl;
//    std::cout << mag << std::endl;
//    std::cout << vN.x << ", " << vN.y << ", " << vN.z << std::endl;
//    std::cout << vNMag << std::endl;

//    std::cout << v3.isZero() << std::endl;


    Vector3D v1 = Vector3D(1.0, 2.0, 3.0);
    Vector3D v2 = Vector3D(4.0, 5.0, 6.0);
    Vector3D v3 = Vector3D(7.0, 8.0, 9.0);

    Matrix3D matrix3D = Matrix3D(v1, v2, v3);

    std::cout << matrix3D(0, 0) << " " << matrix3D(0, 1) << " " << matrix3D(0, 2) << " " << std::endl;
    std::cout << matrix3D(1, 0) << " " << matrix3D(1, 1) << " " << matrix3D(1, 2) << " " << std::endl;
    std::cout << matrix3D(2, 0) << " " << matrix3D(2, 1) << " " << matrix3D(2, 2) << " " << std::endl;

    Vector3D vTeste = matrix3D[0];

    std::cout << vTeste.x << " " << vTeste.y << " " << vTeste.z << " " << std::endl;

    return 0;
}
