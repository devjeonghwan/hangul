#include "hangul.h"
#include <locale.h>
#include <stdio.h>

wchar_t buffer[255] = { 0 };
int cursor = 0;

void OnHangulComposition(HANGUL_COMPOSITION_STATE state, wchar_t character)
{
    buffer[cursor] = character;

    switch (state)
    {
    case HANGUL_COMPOSITION_START:
        wprintf(L"\t HANGUL_COMPOSITION_START\t %C\r\n", character);
        break;
    case HANGUL_COMPOSITION_IN:
        wprintf(L"\t HANGUL_COMPOSITION_IN\t %C\r\n", character);
        break;
    case HANGUL_COMPOSITION_COMPLETE:
        wprintf(L"\t HANGUL_COMPOSITION_COMPLETE\t %C\r\n", character);
        cursor++;
        break;
    case HANGUL_COMPOSITION_NONE:
        wprintf(L"\t HANGUL_COMPOSITION_COMPLETE\t %C\r\n", character);
        cursor++;
        break;
    case HANGUL_COMPOSITION_REMOVE:
        wprintf(L"\t HANGUL_COMPOSITION_REMOVE\t %C\r\n", character);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    HANGUL_CONTEXT context;
    InitializeHangulContext(&context, &OnHangulComposition);

    while (true)
    {
        wchar_t input;
        wscanf(L"%C", &input);

        if (input == '-')
        {
            bool ret = DecomposeHangulCharacter(&context, 0 /* USE_COMPOSITION_DOUBLE_SAME_CONSONANT | USE_COMPOSITION_DOUBLE_LIGATURE_VOWEL */);

            if (!ret && cursor > 0)
            {
                buffer[cursor - 1] = 0;

                cursor--;
            }

            wprintf(L"\t '%S' \r\n", buffer);
        }
        else if (input != L'\n' && input != L'\r' && input != L'\0')
        {
            ComposeHangulCharacter(&context, input, 0 /* USE_COMPOSITION_DOUBLE_SAME_CONSONANT | USE_COMPOSITION_DOUBLE_LIGATURE_VOWEL */);
            wprintf(L"\t '%S' \r\n", buffer);
        }
    }

    return 0;
}