#if 0
//VT 93 COD.001

int obtenerVal() // cualquier función que devuelve un int por valor
{
  //hacer algo
}; 

int main()
{
    auto val{ obtenerVal() }; // compilador deduce que val es de tipo int

    return 0;
}





//VT 93 COD.002
const double hacer()
{
    return 5.6;
}

int main()
{
    const double x{ 7.8 };

    auto x{ x };    // double (const eliminado)
    auto y{ hacer() }; // double (const eliminado)

    return 0;
}




//VT 93 COD.003
const double hacer()
{
    return 5.6;
}

int main()
{
    const double x{ 7.8 };

    const auto x{ x };    // const double (const reaplicado)
    const auto y{ hacer() }; // const double (const reaplicado)

    return 0;
}






//VT 93 COD.004

#include <string>

std::string& obtenerRef() // cualquier función que devuelve una referencia
{
    //hacer algo
} 

int main()
{
    auto ref{ obtenerRef() }; // tipo deducido como std::string (no std::string&)

    return 0;
}






//VT 93 COD.005
#include <string>

std::string& obtenerRef() // cualquier función que devuelve una referencia a const
{
    //hacer algo
} 

int main()
{
    auto ref1{ obtenerRef() };  // std::string (referencia eliminada)
    auto& ref2{ obtenerRef() }; // std::string& (referencia reaplicada)

    return 0;
}






//VT 93 COD.006
const int x;    // esta constante se aplica a x, así que es de alto-nivel
int* const ptr; // esta constante se aplica a ptr, así que es de alto-nivel


//VT 93 COD.007
const int& ref; // esta constante se aplica al objeto que está 
                //siendo referenciado, así que es de bajo-nivel

const int* ptr; // esta constante se aplica al objeto que está 
                //siendo referenciado, así que es de bajo-nivel


//VT 93 COD.008
const int* const ptr; // la const izquierda es de bajo-nivel, 
                      //la const derecha es de alto-nivel




//VT 93 COD.009
#include <string>

const std::string& obtenerRef(); // cualquier función que devuelve una referencia a const

int main()
{
    auto ref1{ obtenerRef() }; // std::string (top-level const y referencia eliminada)

    return 0;
}
#endif






//VT 93 COD.010
#include <string>

const std::string& obtenerRef(); // cualquier función que devuelve una referencia const

int main()
{
    auto ref1{ obtenerRef() };        // std::string (top-level const y referencia eliminados)
    const auto ref2{ obtenerRef() };  // const std::string (const reaplicada, referencia eliminada)

    auto& ref3{ obtenerRef() };       // const std::string& (referencia reaplicada, low-level const no eliminada)
    const auto& ref4{ obtenerRef() }; // const std::string& (reference and const reaplicada)

    return 0;
}





