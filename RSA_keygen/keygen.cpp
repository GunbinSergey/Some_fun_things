#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <ctime>
#include <thread>
#include <chrono>

std::vector<int>* simple_int();


uint16_t gen_simpl_int(std::vector<int>* v);


int main(){

  std::vector<int>* v = simple_int();
  std::cout << "In main " << v->size() << "\n";

  std::cout << gen_simpl_int(v) << '\n';
  std::chrono::miliseconds skip(300);
  std::this_thread::sleep_for(skip);
  std::cout << gen_simpl_int(v) << '\n';

  return 0;

}


uint16_t gen_simpl_int(std::vector<int>* v)
{
  //Возвращает случайное число из векторого простых чичсел
  int32_t side = std::time(nullptr);
  //std::srand(side);
  int len = v->size();

  uint16_t i_rand = 4 + (rand()% (len-4));

  return v->at(i_rand);

}


std::vector<int>* simple_int()
{
  //Генерирует массив  простых чичсел

  //С помощью сита находит простые числа
  std::vector<bool> vec(100, true);
  vec[0] = false;
  vec[1] = false;

  for (int i = 2; i < vec.size(); ++i){
     int st = i;

   if (st* st > vec.size()) {
     break;
   }

     for (int j = st*st; j < vec.size(); j += st){
       vec[j] = false;
     }
  }



  //Запись найденных чисел в массив
  std::vector<int>* vec_int = new std::vector<int>;
  std::cout <<  vec_int->size() << "\n";
  auto p = vec.begin();

  while (p < vec.end()) {
    p = std::find_if(p, vec.end(), [](bool i) {return i == true;});
    vec_int->push_back(p - vec.begin());
    p++;

  }
  vec_int->pop_back();
  return vec_int;
}
