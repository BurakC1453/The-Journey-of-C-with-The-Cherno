#include <iostream>

class Temperature
{
private:
	

	float celsiusToKelvin(float temp)
	{
		return temp + 273.15;
	}
	float celsiusToFahrenheit(float temp)
	{
		return (temp * 9 / 5) + 32;
	}
	float kelvinToCelsius(float temp)
	{
		return temp - 273.15;
	}
	float kelvinToFahrenheit(float temp)
	{
		return (temp - 273.15) * 9 / 5 + 32;
	}
	float FahrenheitToKelvin(float temp)
	{
		return (temp - 32) * 5 / 9 + 273.15;
	}
	float FahrenheitToCelsius(float temp)
	{
		return (temp - 32) * 5 / 9;
	}

public :
	void convertTemperature(float temp, char fromUnit, char toUnit)
	{
		float convertedTemp;
		if (fromUnit == 'C' && toUnit == 'K')
			convertedTemp = celsiusToKelvin(temp);
		else if (fromUnit == 'C' && toUnit == 'F')
			convertedTemp = celsiusToFahrenheit(temp);
		else if (fromUnit == 'K' && toUnit == 'C')
			convertedTemp = kelvinToCelsius(temp);
		else if (fromUnit == 'K' && toUnit == 'F')
			convertedTemp = kelvinToFahrenheit(temp);
		else if (fromUnit == 'F' && toUnit == 'K')
			convertedTemp = FahrenheitToKelvin(temp);
		else if (fromUnit == 'F' && toUnit == 'C')
			convertedTemp = FahrenheitToCelsius(temp);
		else
		{
			std::cout << "Invalid conversion units." << std::endl;
			return;
		}
		std::cout << "Converted Temperature: " << convertedTemp << " " << toUnit << std::endl;
	}
	char fromUnit;
	char toUnit;
	float temp;
};

int main()
{
	int choice = 1;
	
	while (choice != 0)
	{
		Temperature tempConverter;
		std::cout << "Temperature Converter" << std::endl;
		std::cout << "Enter the temperature value: " << std::endl;
		std::cin >> tempConverter.temp;
		std::cout << "Select the unit to convert from (C for Celsius, K for Kelvin, F for Fahrenheit): " << std::endl;
		std::cin >> tempConverter.fromUnit;
		std::cout << "Select the unit to convert to (C for Celsius, K for Kelvin, F for Fahrenheit): " << std::endl;
		std::cin >> tempConverter.toUnit;
		tempConverter.convertTemperature(tempConverter.temp, tempConverter.fromUnit, tempConverter.toUnit);
		std::cout << "Do you want to convert another temperature? (1 for Yes, 0 for No): " << std::endl;
		std::cin >> choice;
	}
	return 0;
}