#include <iostream>

using namespace std;

void smaller(int *min, int *max, int *middle) {
    *max = *middle;

    *middle = floor((*min + *max) / 2);

    if (*max == *middle) {
        *middle--;
    }
}

void bigger(int *min, int *max, int *middle) {
    *min = *middle;

    *middle = floor((*min + *max) / 2);

    if (*max == *middle) {
        *middle++;
    }
}

int main()
{
    /* Алгоритм, который угадает ваше число от 0 до 100 за <= 7 попыток. */

    setlocale(0, "rus");

    while (true)
    {
        int min = 0;
        int max = 100;
        int middle = floor((min + max) / 2);

        char option = ' ';

        cout << "Загадайте число от 0 до 100.\n\n";

        for (int i = 1; i < 8; i++)
        {
            cout << "Попытка #" << i << ", ваше число: " << middle << "?\n";

            cout << "Меньше - '<', Угадал - '=', Больше - '>': ";
            do
            {
                cin >> option;
            } while (option != '<' && option != '=' && option != '>');
            
            switch (option)
            {
            case '<':
                smaller(&min, &max, &middle);
                break;
            case '=':
                cout << "\nОтлично! Я угадал ваше число :)\n";
                system("pause");
                system("cls");
                break;
            case '>':
                bigger(&min, &max, &middle);
                break;
            }
            if (option == '=')
            {
                break;
            }
        }
    }
}