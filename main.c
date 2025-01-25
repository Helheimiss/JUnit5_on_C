#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <math.h>


#define MAX_NAME_SIZE 20
#define USE_LOCALE

#ifdef USE_LOCALE
    #include <locale.h>
#endif


int main(void)
{
    #ifdef USE_LOCALE
        setlocale(LC_ALL, "");
    #endif


    wchar_t people[][MAX_NAME_SIZE] = {L"Иванов", L"Петров"};
    const wchar_t const alphabet_rus_lower[] =  L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const wchar_t const alphabet_rus_bigger[] = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

    int count_peoples = sizeof(people) / sizeof(people[0]);
    for (int human_in_people = 0; human_in_people < count_peoples; human_in_people++)
    {
        int count_alp_peoples = 0;

        int count_alp_name = 0;
        int size_name = 0;
        

        for (int i = 0; i < count_peoples; i++)
        {
            int temp = 0;
            while (people[i][temp] != '\0')
            {
                count_alp_peoples++;
                temp++;
            }
            
        }


        while (people[human_in_people][size_name] != '\0')
        {
            size_name++;
        }
        

        for (int i = 0; i < size_name; i++)
        {
            for (int j = 0; j < 33; j++)
            {
                if (people[human_in_people][i] == alphabet_rus_lower[j] || people[human_in_people][i] == alphabet_rus_bigger[j])
                {
                    count_alp_name += j + 1;
                }
                
            }
        }
        

        // итог
        int var = (int)ceil((double)count_alp_name / (double)count_alp_peoples);
        if (size_name % 2 == 0)
        {
            wprintf(L"%lc%ld%lc ", people[human_in_people][ (int)ceil(size_name / 2.) - 1 ] - 32, var, people[human_in_people][ (int)ceil(size_name / 2.) ] - 32);
        }
        else
        {
            wprintf(L"%lc%ld%lc ", people[human_in_people][ (int)ceil(size_name / 2.) ] - 32, var, people[human_in_people][ (int)ceil(size_name / 2.) - 1 ] - 32);
        }
        
    }
    

    return 0;
}