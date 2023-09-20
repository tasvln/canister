/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>

#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"

using namespace std;

namespace sdds {
  const double PI = 3.14159265;
  const double H_MIN = 10.0;
  const double H_MAX = 40.0;
  const double D_MIN = 10.0;
  const double D_MAX = 30.0;
  const double D_DEFAULT = 10.0;
  const double H_DEFAULT = 13.0;
  const double V_DEFAULT = 0.0;
  const double V_VOL = 0.00001;

  // Set Canister to default state
  void Canister::setToDefault(){
    m_contentName = nullptr;
    m_height = H_DEFAULT;
    m_diameter = D_DEFAULT;
    m_contentVolume = V_DEFAULT;
    m_usable = true;
  }

  // Set Canister name
  void Canister::setName(const char* Cstr){
    if (Cstr != nullptr) {
      if (m_usable) {
        delete[] m_contentName;
        m_contentName = new char[strLen(Cstr) + 1];
        strCpy(m_contentName, Cstr);
      }
    }
  }

  // Check if Canister is empty
  bool Canister::isEmpty() const {
    bool empty = false;

    if (m_contentVolume < V_VOL) {
      empty = true;
    }

    return empty;
  }

  // Check if Canister has same name
  bool Canister::hasSameContent(const Canister& C)const {
    bool same = false;

    if (m_contentName != nullptr && C.m_contentName != nullptr) {
      if (strCmp(m_contentName, C.m_contentName) == 0) {
        same = true;
      }
    }

    return same;
  }

  // Initialize Canister
  Canister::Canister() {
    setToDefault();
  }

  // Initialize Canister with height, diameter and content name
  Canister::Canister(double height, double diameter, const char* contentName){
    setToDefault();

    if ((height >= H_MIN && height <= H_MAX) && (diameter >= D_MIN && diameter <= D_MAX)) {
      m_height = height;
      m_diameter = diameter;
      m_contentVolume = V_VOL;
      setName(contentName);
    } else {
      m_usable = false;
    }
  }

  // Initialize Canister with content name
  Canister::Canister(const char* contentName) {
    setToDefault();
    setName(contentName);
  }

  // Deallocate memory
  Canister::~Canister() {
    clear();
  }

  // Set Canister content
  Canister& Canister::setContent(const char* contentName) {
    if (contentName == nullptr) {
      m_usable = false;
    } else {
      if (isEmpty()) {
        setName(contentName);
      }
      else {
        if (hasSameContent(contentName) != true) {
          m_usable = false;
        }
      }
    }

    return *this;
  }

  // Pour quantity into Canister
  Canister& Canister::pour(double quantity) {
    if (m_usable && quantity > 0 && (quantity + volume() <= capacity())) {
      m_contentVolume += quantity;
    }
    else {
      m_usable = false;
    }

    return *this;
  }

  // Pour Another Canister into Canister
  Canister& Canister::pour(Canister& C) {
    setContent(C.m_contentName);

    if (C.volume() > capacity() - volume()) {
      C.m_contentVolume -= (capacity() - volume());
      m_contentVolume = capacity();
    }
    else 
    {
      pour(C.m_contentVolume);

      C.m_contentVolume = V_DEFAULT;
    }

    return *this;
  }

  // Get Canister volume
  double Canister::volume()const {
    return m_contentVolume;
  }

  // Display Canister Data
  std::ostream& Canister::display()const {
    cout.setf(ios::fixed);
    cout.precision(1);
    cout.width(7);
    cout << capacity();
    cout << "cc (" << m_height << "x" << m_diameter << ") Canister";

    if (m_usable) {
      if (m_contentName != nullptr) {
        cout << " of ";
        cout.width(7);
        cout << volume();
        cout << "cc   " << m_contentName;
      } else {
        return cout;
      }
    }
    else {
      cout << " of Unusable content, discard!";
    }

    return cout;
  }

  // Calculate Canister capacity
  double Canister::capacity() const {
    return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
  }

  // Clear Canister
  void Canister::clear() {
    delete[] m_contentName;
    m_contentName = nullptr;
    m_contentVolume = V_DEFAULT;
    m_usable = true;
  }
}