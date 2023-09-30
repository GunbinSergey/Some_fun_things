#include <iostream>
#include <string>

//Возводит base в степень degree по кольцу bound
int cicle_pow(uint8_t base, int degree, int bound);


int main(int argc, char* argv[])
{

  std::cerr << "Для правильнной работы программы осуществляйте " <<
  "ввод-выввод кодов в программу через файлы" << '\n';

  std::string message;

  const char* temp = argv[2];
  int mod = std::atoi(temp);
  //std::cerr << mod << "\n";


  temp = argv[3];
  int sec_key = std::atoi(temp);
  //std::cerr << sec_key << "\n";


  temp = argv[1];
  //std::cerr << temp << "\n";

    if (temp[0] == 'c') {
      std::cerr << "Режим кодирования " << '\n';
    }
    else if (temp[0] == 'd') {
      std::cerr << "Режим декодирования " << '\n';
      }

    std::getline(std::cin, message);
    for (auto& p : message){
    p = cicle_pow(p, sec_key, mod);
  }

    std::cout << message << "\n";

}

int cicle_pow(uint8_t base, int degree, int bound)
{
    uint8_t result = base;
    for (int i = 1; i < degree; i++){
      result = (result * base) % bound;
    }
  return result;
}
