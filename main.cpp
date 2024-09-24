#include <iostream>
#include <string>
#include <sstream>
using namespace std;
enum switches {
  POWER_SWITCH = 1,
  OUTLETS = 2,
  INNER_LIGHT = 4,
  OUTER_LIGHT = 8,
  HEATING = 16,
  WATER_HEATER = 32,
  AIR_CONDITIONER = 64
};

int setSwitchState(int state, switches key, bool isOn = true) {
  return isOn ? (state | key) : (state & (~key));
};

bool stob(string text) {
  return text == "YES" || text == "yes" || text == "Y" || text == "y" || text == "ON" || text == "on";
}

void printEvents(int currentState, int changes, int time) {
  cout << "-----Changes report------------------------------------------------" << endl;
  for (int i = POWER_SWITCH; i <= AIR_CONDITIONER; i <<= 1) {
    if (changes & i) {
      switch (i) {
        case POWER_SWITCH:
          cout << "Master Power switch: ";
          break;
        case OUTLETS:
          cout << "House outlets: ";
          break;
        case INNER_LIGHT:
          cout << "Indoor light: ";
          break;
        case OUTER_LIGHT:
          cout << "Outdoor light: ";
          break;
        case HEATING:
          cout << "House warming system: ";
          break;
        case WATER_HEATER:
          cout << "Water warming system: ";
          break;
        case AIR_CONDITIONER:
          cout << "Air conditioner: ";
          break;
      }
      if (!(currentState & i)) {
        cout << "OFF" << endl;
      } else {
        cout << "ON" << endl;
        if (i == INNER_LIGHT) {
          if (time > 16 && time <= 22) {
            cout << "Light color temperature: " << 5000 - ((5000 - 2700) / 6) * (time - 16) << "K" << endl;
          } else {
            cout << "Light color temperature: " << (time > 22 ? 2700 : 5000) << "K" << endl;
          }
        }
      }
    }
  }
  cout << "-------------------------------------------------------------------" << endl;
}
int main() {
  cout << "SMART HOUSE." << endl;
  int smartHomeState = 0;
  for (int day = 0; day < 2; day++) {
    for (int hour = 0; hour <= 23; hour++) {
      cout << "Current day: " << day << " Current time: " << hour << ":00" << endl;
      int previousState = smartHomeState;
      stringstream inputData;
      cout << "You must enter information for Smart House in one string by next order:" << endl;
      cout << "State of Master Power switch (ON/OFF)" << endl;
      cout << "State of house outlets (ON/OFF)" << endl;
      cout << "State of light inside house (ON/OFF)" << endl;
      cout << "Any movements outside house (YES/NO)" << endl;
      cout << "Air temperature inside house (integer value)" << endl;
      cout << "Air temperature outside house (integer value)" << endl;
      cout << "Enter the information: ";
      string answer;
      getline(cin, answer);
      inputData << answer;
      string powerSwitch, outlets, innerLight, motion, indoorTemp, outdoorTemp;
      int insideTemperature = 0, outsideTemperature = 0;
      inputData >> powerSwitch >> outlets >> innerLight >> motion >> indoorTemp >> outdoorTemp;
      if (!stob(powerSwitch)) {
        smartHomeState = setSwitchState(smartHomeState, POWER_SWITCH, stob(powerSwitch));
        smartHomeState = setSwitchState(smartHomeState, OUTLETS, stob(powerSwitch));
        smartHomeState = setSwitchState(smartHomeState, INNER_LIGHT, stob(powerSwitch));
        smartHomeState = setSwitchState(smartHomeState, OUTER_LIGHT, stob(powerSwitch));
        smartHomeState = setSwitchState(smartHomeState, HEATING, stob(powerSwitch));
        smartHomeState = setSwitchState(smartHomeState, WATER_HEATER, stob(powerSwitch));
        smartHomeState = setSwitchState(smartHomeState, AIR_CONDITIONER, stob(powerSwitch));
      } else {
        smartHomeState = setSwitchState(smartHomeState, POWER_SWITCH, stob(powerSwitch));
        smartHomeState = setSwitchState(smartHomeState, OUTLETS, stob(outlets));
        smartHomeState = setSwitchState(smartHomeState, INNER_LIGHT, stob(innerLight));
        if (insideTemperature < 22) {
          smartHomeState = setSwitchState(smartHomeState, HEATING);
        }
        if (insideTemperature <= 25) {
          smartHomeState = setSwitchState(smartHomeState, AIR_CONDITIONER, false);
        }
        if (insideTemperature >= 25) {
          smartHomeState = setSwitchState(smartHomeState, HEATING, false);
        }
        if (insideTemperature >= 30) {
          smartHomeState = setSwitchState(smartHomeState, AIR_CONDITIONER);
        }
        if (outsideTemperature < 0) {
          smartHomeState = setSwitchState(smartHomeState, WATER_HEATER);
        } else if (outsideTemperature > 5) {
          smartHomeState = setSwitchState(smartHomeState, WATER_HEATER, false);
        }
        if (hour < 5 || hour > 16) {
          smartHomeState = setSwitchState(smartHomeState, OUTER_LIGHT, stob(motion));
        } else {
          smartHomeState = setSwitchState(smartHomeState, OUTER_LIGHT, false);
        }
      }
      int diff = previousState ^ smartHomeState;
      printEvents(smartHomeState, diff, hour);
    }
  }
}

/*
Разработайте упрощённую модель умного дома для дачи. Выполните симуляцию его работы на протяжении двух дней. 
Стартовое время для симуляции умного дома 00:00. Есть несколько датчиков: датчик температуры снаружи, датчик температуры внутри дома.
В доме расположен электронный умный щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых устройств или групп устройств:
отключение и включение питания всего дома;
основные розетки дома;
свет внутри дома;
наружный свет в саду;
отопление в помещении;
отопление водопровода, идущего из скважины с насосом;
кондиционер в помещении.
Есть несколько условий по включению/отключению техники в доме и вне его.

Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода. 
Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить садовое освещение. 
Если движения нет или время не вечернее, то света снаружи быть не должно.
Если температура в помещении упала ниже 22 °С, должно включиться отопление.
Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.
Если температура в помещении поднялась до 30 °С, включается кондиционер. Как только температура становится 25 °С, кондиционер отключается.
Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного нахождения.
Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться с 5000K до 2700К. 
Разумеется, это изменение должно происходить, если свет сейчас включён. В 00:00 температура сбрасывается до 5000К.
Все события по отключению и включению устройств должны выводиться в консоль явным образом. 
Если устройство не изменило своё состояние (осталось включённым или выключенным), событие генерироваться не должно! 
Если свет в доме включён, должна отображаться текущая цветовая температура.

Программа выполняется следующим образом:

Каждый час пользователь сообщает состояние всех основных датчиков и света (температура снаружи, температура внутри, есть ли движение снаружи, 
включён ли свет в доме).
Данные параметры вводятся разом в одну строку через пробел, а потом парсятся в переменные из строкового буфера stringstream.
Информация о движении выводится в формате yes/no.
Включение и отключение света происходит с помощью on/off.
*/