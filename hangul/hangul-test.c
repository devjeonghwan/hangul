#include "hangul.h"

#include <locale.h>

wchar_t buffer[255] = { 0 };
int cursor = 0;

void OnHangulComposition(HANGUL_COMPOSITION_STATE state, wchar_t character)
{
    buffer[cursor] = character;

    switch (state)
    {
    case HANGUL_COMPOSITION_START:
        wprintf(L"\t HANGUL_COMPOSITION_START\t %c\r\n", character);

        break;
    case HANGUL_COMPOSITION_IN:
        wprintf(L"\t HANGUL_COMPOSITION_IN\t %c\r\n", character);

        break;
    case HANGUL_COMPOSITION_COMPLETE:
        wprintf(L"\t HANGUL_COMPOSITION_COMPLETE\t %c\r\n", character);

        cursor++;
        break;
    case HANGUL_COMPOSITION_NONE:
        wprintf(L"\t HANGUL_COMPOSITION_COMPLETE\t %c\r\n", character);

        cursor++;
        break;
    case HANGUL_COMPOSITION_REMOVE:
        wprintf(L"\t HANGUL_COMPOSITION_REMOVE\t %c\r\n", character);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "korean");

    HANGUL_CONTEXT context;

    InitializeHangulContext(&context, &OnHangulComposition);

    while (true)
    {
        wchar_t input;

        wscanf_s(L"%c", &input);

        if (input == '-')
        {
            bool ret = DecomposeHangulCharacter(&context, 0 /* USE_COMPOSITION_DOUBLE_SAME_CONSONANT | USE_COMPOSITION_DOUBLE_LIGATURE_VOWEL */);

            if (!ret)
            {
                if (cursor > 0)
                {
                    buffer[cursor - 1] = 0;

                    cursor--;
                }
            }

            wprintf(L"\t '%s' \r\n", buffer);
        }
        else if (input != L'\n' && input != L'\r' && input != L'\0')
        {
            ComposeHangulCharacter(&context, input, 0 /* USE_COMPOSITION_DOUBLE_SAME_CONSONANT | USE_COMPOSITION_DOUBLE_LIGATURE_VOWEL */);
            wprintf(L"\t '%s' \r\n", buffer);
        }
    }
}