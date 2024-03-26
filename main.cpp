#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>

//scrivo funzione per mappare i valori da [1,5] a [-1,2]
double mapValue(double value) {
    return (value + 1.0) * 3.0/2.0 + 2.0;
    }
int main() {
    std::ifstream inputFile("/Users/mariateresapinna/Desktop/PCS2024_Exercises/Esercitazione_1_IO/Exercise2/data.csv"); //apertura file input
    std::ofstream outputfile("/Users/mariateresapinna/Desktop/PCS2024_Exercises/Esercitazione_1_IO/Exercise2/result.csv"); //apertura file output

 //controllo che il file viene aperto in modo corretto
  if (!inputFile.is_open()) {
         std::cerr << "Impossibile aprire il file data.csv" <<std::endl;
         return 1;
     }
  if (!outputfile.is_open()) {
         std::cerr << "Impossibile creare il file result.csv" <<std::endl;
      return 1;
     }

  std::vector<double> mappedValues;
  double value;

  // Leggo i valori dal file e li mappo
  while (inputFile >> value) {
         mappedValues.push_back(mapValue(value));
     }
 //calcolo la media e scrivo risultati
     outputfile << " N Mean\n ";
     std::cout << "N Mean\n";
     double sum = 0;

     for (size_t i = 0; i < mappedValues.size(); ++i) {
         sum += mappedValues[i];
         double mean = sum / (i + 1);
         outputfile << i+1 << " " << std::fixed << std::setprecision (16) << mean << "\n";
         std::cout << i+1 << " " << std::fixed << std::setprecision (16) << mean << "\n";
     }

     std::string command = "open -a \"Microsoft Excel\" /Users/mariateresapinna/Desktop/PCS2024_Exercises/Esercitazione_1_IO/Exercise2/data.csv";
     system(command.c_str());

     return 0;
}
