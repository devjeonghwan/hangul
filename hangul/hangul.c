#include "hangul.h"

#pragma region Hangul Letter Constants
const wchar_t FIRST_HANGUL_LETTERS[] = {
    L'ㄱ', L'ㄲ', L'ㄴ', L'ㄷ', L'ㄸ', L'ㄹ', L'ㅁ', L'ㅂ', L'ㅃ', L'ㅅ', L'ㅆ', L'ㅇ', L'ㅈ', L'ㅉ', L'ㅊ', L'ㅋ', L'ㅌ', L'ㅍ', L'ㅎ'
};
const size_t FIRST_HANGUL_LETTERS_LENGTH = sizeof(FIRST_HANGUL_LETTERS) / sizeof(wchar_t);

const wchar_t MIDDLE_HANGUL_LETTERS[] = {
    L'ㅏ', L'ㅐ', L'ㅑ', L'ㅒ', L'ㅓ', L'ㅔ', L'ㅕ', L'ㅖ', L'ㅗ', L'ㅘ', L'ㅙ', L'ㅚ', L'ㅛ', L'ㅜ', L'ㅝ', L'ㅞ', L'ㅟ', L'ㅠ', L'ㅡ', L'ㅢ', L'ㅣ'
};
const size_t MIDDLE_HANGUL_LETTERS_LENGTH = sizeof(MIDDLE_HANGUL_LETTERS) / sizeof(wchar_t);

const wchar_t LAST_HANGUL_LETTERS[] = {
    L' ', L'ㄱ', L'ㄲ', L'ㄳ', L'ㄴ', L'ㄵ', L'ㄶ', L'ㄷ', L'ㄹ', L'ㄺ', L'ㄻ', L'ㄼ', L'ㄽ', L'ㄾ', L'ㄿ', L'ㅀ', L'ㅁ', L'ㅂ', L'ㅄ', L'ㅅ', L'ㅆ', L'ㅇ', L'ㅈ', L'ㅊ', L'ㅋ', L'ㅌ', L'ㅍ', L'ㅎ'
};
const size_t LAST_HANGUL_LETTERS_LENGTH = sizeof(LAST_HANGUL_LETTERS) / sizeof(wchar_t);

const int HANGUL_LETTER_BEGIN = L'ㄱ';
const int HANGUL_LETTER_END = L'ㅣ';
const int HANGUL_CHARACTER_BEGIN = L'가';
const int HANGUL_CHARACTER_END = L'힣';
#pragma endregion

#pragma region Double Vowel Letter Constants
const wchar_t DOUBLE_VOWEL_HANGUL_LETTERS[][3] = {
    {L'ㅘ', L'ㅗ',  L'ㅏ'},
    {L'ㅙ', L'ㅗ',  L'ㅐ'},
    {L'ㅚ', L'ㅗ',  L'ㅣ'},
    {L'ㅝ', L'ㅜ',  L'ㅓ'},
    {L'ㅞ', L'ㅜ',  L'ㅔ'},
    {L'ㅟ', L'ㅜ',  L'ㅣ'},
    {L'ㅢ', L'ㅡ',  L'ㅣ'}
};
const size_t DOUBLE_VOWEL_HANGUL_LETTERS_LENGTH = sizeof(DOUBLE_VOWEL_HANGUL_LETTERS) / sizeof(wchar_t) / 3;

const wchar_t DOUBLE_LIGATURE_VOWEL_HANGUL_LETTERS[][3] = {
    {L'ㅐ', L'ㅏ',  L'ㅣ'},
    {L'ㅒ', L'ㅑ',  L'ㅣ'},
    {L'ㅔ', L'ㅓ',  L'ㅣ'},
    {L'ㅖ', L'ㅕ',  L'ㅣ'}
};
const size_t DOUBLE_LIGATURE_VOWEL_HANGUL_LETTERS_LENGTH = sizeof(DOUBLE_LIGATURE_VOWEL_HANGUL_LETTERS) / sizeof(wchar_t) / 3;
#pragma endregion

#pragma region Double Consonant Letter Constants
const wchar_t DOUBLE_CONSONANT_HANGUL_LETTERS[][3] = {
    {L'ㄳ', L'ㄱ',  L'ㅅ'},
    {L'ㄵ', L'ㄴ',  L'ㅈ'},
    {L'ㄶ', L'ㄴ',  L'ㅎ'},
    {L'ㄺ', L'ㄹ',  L'ㄱ'},
    {L'ㄻ', L'ㄹ',  L'ㅁ'},
    {L'ㄼ', L'ㄹ',  L'ㅂ'},
    {L'ㄽ', L'ㄹ',  L'ㅅ'},
    {L'ㄾ', L'ㄹ',  L'ㅌ'},
    {L'ㄿ', L'ㄹ',  L'ㅍ'},
    {L'ㅀ', L'ㄹ',  L'ㅎ'},
    {L'ㅄ', L'ㅂ',  L'ㅅ'}
};
const size_t DOUBLE_CONSONANT_HANGUL_LETTERS_LENGTH = sizeof(DOUBLE_CONSONANT_HANGUL_LETTERS) / sizeof(wchar_t) / 3;

const wchar_t DOUBLE_SAME_CONSONANT_HANGUL_LETTERS[][3] = {
    {L'ㄲ', L'ㄱ',  L'ㄱ'},
    {L'ㄸ', L'ㄷ',  L'ㄷ'},
    {L'ㅃ', L'ㅂ',  L'ㅂ'},
    {L'ㅆ', L'ㅅ',  L'ㅅ'},
    {L'ㅉ', L'ㅈ',  L'ㅈ'}
};
const size_t DOUBLE_SAME_CONSONANT_HANGUL_LETTERS_LENGTH = sizeof(DOUBLE_SAME_CONSONANT_HANGUL_LETTERS) / sizeof(wchar_t) / 3;
#pragma endregion

#pragma region Get Functions
extern inline int _GetHangulLetterIndex(const wchar_t* letters, const size_t length, const wchar_t letter)
{
    for (int index = 0; index < length; index++)
    {
        if (letters[index] == letter)
        {
            return index;
        }
    }

    return -1;
}

extern inline int _GetFirstHangulLetterIndex(const wchar_t letter)
{
    return _GetHangulLetterIndex(FIRST_HANGUL_LETTERS, FIRST_HANGUL_LETTERS_LENGTH, letter);
}

extern inline int _GetMiddleHangulLetterIndex(const wchar_t letter)
{
    return _GetHangulLetterIndex(MIDDLE_HANGUL_LETTERS, MIDDLE_HANGUL_LETTERS_LENGTH, letter);
}

extern inline int _GetLastHangulLetterIndex(const wchar_t letter)
{
    return _GetHangulLetterIndex(LAST_HANGUL_LETTERS, LAST_HANGUL_LETTERS_LENGTH, letter);
}

extern inline bool _ContainsFirstHangulLetterIndex(const int index)
{
    return index >= 0 && index < FIRST_HANGUL_LETTERS_LENGTH;
}

extern inline bool _ContainsMiddleHangulLetterIndex(const int index)
{
    return index >= 0 && index < MIDDLE_HANGUL_LETTERS_LENGTH;
}

extern inline bool _ContainsLastHangulLetterIndex(const int index)
{
    return index >= 1 && index < LAST_HANGUL_LETTERS_LENGTH;
}
#pragma endregion

#pragma region Compose Functions
extern inline wchar_t _ComposeDoubleHangulLetter(const wchar_t* letters, const size_t length, const wchar_t letter1, const wchar_t letter2)
{
    for (int index = 0; index < length; index++)
    {
        int globalIndex = index * 3;

        if (letters[globalIndex + 1] == letter1 && letters[globalIndex + 2] == letter2)
        {
            return letters[globalIndex];
        }
    }

    return L'\0';
}

extern inline wchar_t _ComposeDoubleVowelHangulLetter(const wchar_t letter1, const wchar_t letter2)
{
    return _ComposeDoubleHangulLetter((const wchar_t*)DOUBLE_VOWEL_HANGUL_LETTERS, DOUBLE_VOWEL_HANGUL_LETTERS_LENGTH, letter1, letter2);
}

extern inline wchar_t _ComposeDoubleLigatureVowelHangulLetter(const wchar_t letter1, const wchar_t letter2)
{
    return _ComposeDoubleHangulLetter((const wchar_t*)DOUBLE_LIGATURE_VOWEL_HANGUL_LETTERS, DOUBLE_LIGATURE_VOWEL_HANGUL_LETTERS_LENGTH, letter1, letter2);
}

extern inline wchar_t _ComposeDoubleConsonantHangulLetter(const wchar_t letter1, const wchar_t letter2)
{
    return _ComposeDoubleHangulLetter((const wchar_t*)DOUBLE_CONSONANT_HANGUL_LETTERS, DOUBLE_CONSONANT_HANGUL_LETTERS_LENGTH, letter1, letter2);
}

extern inline wchar_t _ComposeDoubleSameConsonantHangulLetter(const wchar_t letter1, const wchar_t letter2)
{
    return _ComposeDoubleHangulLetter((const wchar_t*)DOUBLE_SAME_CONSONANT_HANGUL_LETTERS, DOUBLE_SAME_CONSONANT_HANGUL_LETTERS_LENGTH, letter1, letter2);
}

extern inline wchar_t _ComposeHangulCharacter(const int firstLetterIndex, const int middleLetterIndex, const int lastLetterIndex)
{
    bool firstLetterExists = _ContainsFirstHangulLetterIndex(firstLetterIndex);
    bool middleLetterExists = _ContainsMiddleHangulLetterIndex(middleLetterIndex);
    bool lastLetterExists = _ContainsLastHangulLetterIndex(lastLetterIndex);

    if (firstLetterExists && !middleLetterExists && !lastLetterExists)
        return FIRST_HANGUL_LETTERS[firstLetterIndex];

    if (!firstLetterExists && middleLetterExists && !lastLetterExists)
        return MIDDLE_HANGUL_LETTERS[middleLetterIndex];

    if (!firstLetterExists && !middleLetterExists && lastLetterExists)
        return LAST_HANGUL_LETTERS[lastLetterIndex];

    if (!firstLetterExists && !middleLetterExists && !lastLetterExists)
        return L'\0';

    wchar_t result = HANGUL_CHARACTER_BEGIN +
        ((firstLetterExists ? firstLetterIndex : 0) * (int)MIDDLE_HANGUL_LETTERS_LENGTH +
         (middleLetterExists ? middleLetterIndex : 0)) * (int)LAST_HANGUL_LETTERS_LENGTH +
        (lastLetterExists ? lastLetterIndex : 0);

    if (!IsHangul(result))
    {
        return L'\0';
    }

    return result;
}
#pragma endregion

#pragma region Decompose Functions
extern inline bool _DecomposeDoubleHangulLetter(const wchar_t* letters, const size_t length, const wchar_t letter, wchar_t* letter1, wchar_t* letter2)
{
    for (int index = 0; index < length; index++)
    {
        int globalIndex = index * 3;

        if (letters[globalIndex] == letter)
        {
            *letter1 = letters[globalIndex + 1];
            *letter2 = letters[globalIndex + 2];

            return true;
        }
    }

    return false;
}

extern inline bool _DecomposeDoubleVowelHangulLetter(const wchar_t letter, wchar_t* letter1, wchar_t* letter2)
{
    return _DecomposeDoubleHangulLetter((const wchar_t*)DOUBLE_VOWEL_HANGUL_LETTERS, DOUBLE_VOWEL_HANGUL_LETTERS_LENGTH, letter, letter1, letter2);
}

extern inline bool _DecomposeDoubleLigatureVowelHangulLetter(const wchar_t letter, wchar_t* letter1, wchar_t* letter2)
{
    return _DecomposeDoubleHangulLetter((const wchar_t*)DOUBLE_LIGATURE_VOWEL_HANGUL_LETTERS, DOUBLE_LIGATURE_VOWEL_HANGUL_LETTERS_LENGTH, letter, letter1, letter2);
}

extern inline bool _DecomposeDoubleConsonantHangulLetter(const wchar_t letter, wchar_t* letter1, wchar_t* letter2)
{
    return _DecomposeDoubleHangulLetter((const wchar_t*)DOUBLE_CONSONANT_HANGUL_LETTERS, DOUBLE_CONSONANT_HANGUL_LETTERS_LENGTH, letter, letter1, letter2);
}

extern inline bool _DecomposeDoubleSameConsonantHangulLetter(const wchar_t letter, wchar_t* letter1, wchar_t* letter2)
{
    return _DecomposeDoubleHangulLetter((const wchar_t*)DOUBLE_SAME_CONSONANT_HANGUL_LETTERS, DOUBLE_SAME_CONSONANT_HANGUL_LETTERS_LENGTH, letter, letter1, letter2);
}
#pragma endregion

#pragma region Update Functions
extern inline void _UpdateHangulContext(HANGUL_CONTEXT* context, const wchar_t character, const bool combining, const HANGUL_COMPOSITION_STATE state)
{
    context->buffer = character;
    context->combining = combining;

    context->callback(state, character);
}
#pragma endregion

bool IsHangulLetter(const wchar_t character)
{
    return HANGUL_LETTER_BEGIN <= character && HANGUL_LETTER_END >= character;
}

bool IsHangulCharacter(const wchar_t character)
{
    return HANGUL_CHARACTER_BEGIN <= character && HANGUL_CHARACTER_END >= character;
}

bool IsHangul(const wchar_t character)
{
    return IsHangulLetter(character) || IsHangulCharacter(character);
}

void InitializeHangulContext(HANGUL_CONTEXT* context, HANGUL_COMPOSITION_CALLBACK callback)
{
    context->buffer = L'\0';

    context->callback = callback;
    context->combining = false;
}

void ComposeHangulCharacter(HANGUL_CONTEXT* context, const wchar_t typed, unsigned char flags)
{
    wchar_t baseCharacter = context->buffer;

    if (IsHangul(typed))
    {
        // 만약 기존 문자가 비어있다면 바로 문자 삽입
        // Update character to typed character if existing character is empty
        if (baseCharacter == L'\0')
        {
            // 첫 문자를 입력하고 조합 모드 활성화
            // Active Composition Mode
            _UpdateHangulContext(context, typed, true, HANGUL_COMPOSITION_START);

            return;
        }

        // 입력된 문자의 초성, 중성, 종성 별 인덱스 찾기
        // Check typed character's level of letter
        int typedFirstLetterIndex = _GetFirstHangulLetterIndex(typed);
        int typedMiddleLetterIndex = _GetMiddleHangulLetterIndex(typed);
        int typedLastLetterIndex = _GetLastHangulLetterIndex(typed);

        bool typedFirstLetterExists = _ContainsFirstHangulLetterIndex(typedFirstLetterIndex);
        bool typedMiddleLetterExists = _ContainsMiddleHangulLetterIndex(typedMiddleLetterIndex);
        bool typedLastLetterExists = _ContainsLastHangulLetterIndex(typedLastLetterIndex);

        int baseFirstLetterIndex;
        int baseMiddleLetterIndex;
        int baseLastLetterIndex;

        if (IsHangulLetter(baseCharacter))
        {
            // 조합 문자가 아닌 경우 분해를 통해서 찾지 못하기 때문에 단일 문자 결과를 인용
            // If character is not combined, each letter can't decompose. so using single letter.
            baseFirstLetterIndex = _GetFirstHangulLetterIndex(baseCharacter);
            baseMiddleLetterIndex = _GetMiddleHangulLetterIndex(baseCharacter);
            baseLastLetterIndex = _ContainsFirstHangulLetterIndex(baseFirstLetterIndex) ? -1 : _GetLastHangulLetterIndex(baseCharacter);
        }
        else
        {
            // 기존 조합 문자를 분해하고 초성, 중성, 종성 별 인덱스 찾기
            // Decompose base character
            const size_t MIDDLE_LAST_STRIDE = MIDDLE_HANGUL_LETTERS_LENGTH * LAST_HANGUL_LETTERS_LENGTH;

            int baseUnicode = baseCharacter - HANGUL_CHARACTER_BEGIN;
            int baseFirstLetterRemainIndex = baseUnicode % (int)MIDDLE_LAST_STRIDE;

            baseFirstLetterIndex = baseUnicode / (int)MIDDLE_LAST_STRIDE;
            baseMiddleLetterIndex = baseFirstLetterRemainIndex / (int)LAST_HANGUL_LETTERS_LENGTH;
            baseLastLetterIndex = baseFirstLetterRemainIndex % (int)LAST_HANGUL_LETTERS_LENGTH;
        }

        bool baseFirstLetterExists = _ContainsFirstHangulLetterIndex(baseFirstLetterIndex);
        bool baseMiddleLetterExists = _ContainsMiddleHangulLetterIndex(baseMiddleLetterIndex);
        bool baseLastLetterExists = _ContainsLastHangulLetterIndex(baseLastLetterIndex);

        // 기존 문자가 초성인 상황에서 초성이 입력되었으면
        // If typed character is first letter and existing character is first letter
        if (baseFirstLetterExists && !baseMiddleLetterExists && !baseLastLetterExists && typedFirstLetterExists)
        {
            // 서로 다른 초성 간 조합 (ㄱ + ㅅ = ㄳ)
            // Compose different first letters (ㄱ + ㅅ = ㄳ)
            wchar_t composedDoubleConsonantLetter = _ComposeDoubleConsonantHangulLetter(FIRST_HANGUL_LETTERS[baseFirstLetterIndex], typed);
            int composedDoubleConsonantLetterIndex = _GetLastHangulLetterIndex(composedDoubleConsonantLetter);

            if (_GetLastHangulLetterIndex(composedDoubleConsonantLetterIndex))
            {
                baseFirstLetterIndex = -1;
                baseLastLetterIndex = composedDoubleConsonantLetterIndex;

                goto COMPOSING;
            }

            if (flags & USE_COMPOSITION_DOUBLE_SAME_CONSONANT)
            {
                // 같은 초성 간 조합 (ㄱ + ㄱ = ㄲ)
                // Compose same first letters (ㄱ + ㄱ = ㄲ)
                wchar_t composedDoubleSameConsonantLetter = _ComposeDoubleSameConsonantHangulLetter(FIRST_HANGUL_LETTERS[baseFirstLetterIndex], typed);
                int composedDoubleSameConsonantLetterIndex = _GetFirstHangulLetterIndex(composedDoubleSameConsonantLetter);

                if (_ContainsFirstHangulLetterIndex(composedDoubleSameConsonantLetterIndex))
                {
                    baseFirstLetterIndex = composedDoubleSameConsonantLetterIndex;

                    goto COMPOSING;
                }
            }
        }

        // 기존 문자가 초성과 중성의 조합인 상황에서 중성이 입력되었으면
        // If typed character is middle letter and existing character is first and middle letter
        if (baseFirstLetterExists && baseMiddleLetterExists && !baseLastLetterExists && typedMiddleLetterExists)
        {
            // 서로 다른 중성 간 조합 (ㅡ + ㅣ = ㅢ)
            // Compose different middle letters (ㅡ + ㅣ = ㅢ)
            wchar_t composedDoubleVowelLetter = _ComposeDoubleVowelHangulLetter(MIDDLE_HANGUL_LETTERS[baseMiddleLetterIndex], typed);
            int composedDoubleVowelLetterIndex = _GetMiddleHangulLetterIndex(composedDoubleVowelLetter);

            if (_ContainsMiddleHangulLetterIndex(composedDoubleVowelLetterIndex))
            {
                baseMiddleLetterIndex = composedDoubleVowelLetterIndex;

                goto COMPOSING;
            }

            if (flags & USE_COMPOSITION_DOUBLE_LIGATURE_VOWEL)
            {
                // 합자 중성 조합 (ㅏ + ㅣ = ㅐ)
                // Compose ligature middle letters (ㅏ + ㅣ = ㅐ)
                wchar_t composedDoubleLigatureVowelLetter = _ComposeDoubleLigatureVowelHangulLetter(MIDDLE_HANGUL_LETTERS[baseMiddleLetterIndex], typed);
                int composedDoubleLigatureVowelLetterIndex = _GetMiddleHangulLetterIndex(composedDoubleLigatureVowelLetter);

                if (_ContainsMiddleHangulLetterIndex(composedDoubleLigatureVowelLetterIndex))
                {
                    baseMiddleLetterIndex = composedDoubleLigatureVowelLetterIndex;

                    goto COMPOSING;
                }
            }
        }

        // 기존 문자가 완전 조합인 상황에서 종성이 입력되었으면
        // If typed character is last letter and existing character is completely combine
        if (baseFirstLetterExists && baseMiddleLetterExists && baseLastLetterExists && typedLastLetterExists)
        {
            // 서로 다른 종성 간 조합 (각 + ㅅ = 갃)
            // Compose different last letters (각 + ㅅ = 갃)
            wchar_t composedDoubleConsonantLetter = _ComposeDoubleConsonantHangulLetter(LAST_HANGUL_LETTERS[baseLastLetterIndex], typed);
            int composedDoubleConsonantLetterIndex = _GetLastHangulLetterIndex(composedDoubleConsonantLetter);

            if (_ContainsLastHangulLetterIndex(composedDoubleConsonantLetterIndex))
            {
                baseLastLetterIndex = composedDoubleConsonantLetterIndex;

                goto COMPOSING;
            }

            if (flags & USE_COMPOSITION_DOUBLE_SAME_CONSONANT)
            {
                // 같은 종성 간 조합 (각 + ㄱ = 갂)
                // Compose same last letters (각 + ㄱ = 갂)
                wchar_t composedDoubleSameConsonantLetter = _ComposeDoubleSameConsonantHangulLetter(LAST_HANGUL_LETTERS[baseLastLetterIndex], typed);
                int composedDoubleSameConsonantLetterIndex = _GetLastHangulLetterIndex(composedDoubleSameConsonantLetter);

                if (_ContainsLastHangulLetterIndex(composedDoubleSameConsonantLetterIndex))
                {
                    baseLastLetterIndex = composedDoubleSameConsonantLetterIndex;

                    goto COMPOSING;
                }
            }
        }

        // 기존 문자가 초성인 상황에서 중성이 입력되었으면
        // If typed character is middle letter and existing character is first letter
        if (baseFirstLetterExists && !baseMiddleLetterExists && !baseLastLetterExists && typedMiddleLetterExists)
        {
            baseMiddleLetterIndex = typedMiddleLetterIndex;

            goto COMPOSING;
        }

        // 기존 문자가 초성과 중성인 상황에서 종성이 입력되었으면
        // If typed character is last letter and existing character is first and middle letter
        if (baseFirstLetterExists && baseMiddleLetterExists && !baseLastLetterExists && typedLastLetterExists)
        {
            baseLastLetterIndex = typedLastLetterIndex;

            goto COMPOSING;
        }

        // 기존 문자가 완전 조합인 상황에서 중성이 입력되었으면
        // If typed character is middle letter and existing character is completely combine
        if (baseLastLetterExists && typedMiddleLetterExists)
        {
            wchar_t baseLastLetter = LAST_HANGUL_LETTERS[baseLastLetterIndex];

            int decomposedLetter1 = -1;
            int decomposedLetter2 = -1;
            wchar_t letter1 = '\0';
            wchar_t letter2 = '\0';

            // 종성 분해
            // Decompose last letters
            if (_DecomposeDoubleConsonantHangulLetter(baseLastLetter, &letter1, &letter2))          // (ㄳ -> ㄱ, ㅅ)
            {
                decomposedLetter1 = _GetLastHangulLetterIndex(letter1);
                decomposedLetter2 = _GetFirstHangulLetterIndex(letter2);
            }
            else if (flags & USE_COMPOSITION_DOUBLE_SAME_CONSONANT &&
                     _DecomposeDoubleSameConsonantHangulLetter(baseLastLetter, &letter1, &letter2))  // (ㄲ -> ㄱ, ㄱ)
            {
                decomposedLetter1 = _GetLastHangulLetterIndex(letter1);
                decomposedLetter2 = _GetFirstHangulLetterIndex(letter2);
            }
            else                                                                                    // (ㄱ -> X, ㄱ)
            {
                decomposedLetter1 = 0;
                decomposedLetter2 = _GetFirstHangulLetterIndex(baseLastLetter);
            }


            if (_ContainsFirstHangulLetterIndex(decomposedLetter2))
            {
                // 만약 기존 문자에 종성이 이미 있다면 다음 문자로 연결 될 수 있음 (각 + ㅏ = 가가)
                // If character already has last letter, it can be decompose to next character (각 + ㅏ = 가가)
                wchar_t decomposedHangul = _ComposeHangulCharacter(baseFirstLetterIndex, baseMiddleLetterIndex, decomposedLetter1);
                wchar_t composedHangul = _ComposeHangulCharacter(decomposedLetter2, typedMiddleLetterIndex, 0);

                if (decomposedHangul != '\0' && composedHangul != '\0')
                {
                    _UpdateHangulContext(context, decomposedHangul, false, HANGUL_COMPOSITION_COMPLETE);
                    _UpdateHangulContext(context, composedHangul, true, HANGUL_COMPOSITION_START);

                    return;
                }
            }
        }

        goto ESCAPE_COMPOSING;

    COMPOSING:
        // 모든 문자 조합
        // Compose letters
        baseCharacter = _ComposeHangulCharacter(baseFirstLetterIndex, baseMiddleLetterIndex, baseLastLetterIndex);

        if (baseCharacter != '\0')
        {
            _UpdateHangulContext(context, baseCharacter, true, HANGUL_COMPOSITION_IN);

            return;
        }

    ESCAPE_COMPOSING:
        // 조합 중이었다면 기존 문자 마무리
        // Update existing characters if state was combining
        if (context->combining)
        {
            _UpdateHangulContext(context, context->buffer, false, HANGUL_COMPOSITION_COMPLETE);
        }

        // 조합 할 수 없으므로 입력된 문자를 추가
        // Update typed character directly because failed compose
        _UpdateHangulContext(context, typed, true, HANGUL_COMPOSITION_START);

        return;
    }
    else
    {
        // 조합 중이었다면 기존 문자 마무리
        // Update existing characters if state was combining
        if (context->combining)
        {
            _UpdateHangulContext(context, context->buffer, false, HANGUL_COMPOSITION_COMPLETE);
        }

        // 일반 문자이므로 입력된 문자를 추가
        // Update typed character directly because typed character is non-composable character
        _UpdateHangulContext(context, typed, false, HANGUL_COMPOSITION_NONE);

        return;
    }

    return;
}

bool DecomposeHangulCharacter(HANGUL_CONTEXT* context, unsigned char flags)
{
    wchar_t baseCharacter = context->buffer;

    if (IsHangul(baseCharacter) && context->combining)
    {
        int baseFirstLetterIndex;
        int baseMiddleLetterIndex;
        int baseLastLetterIndex;

        if (IsHangulLetter(baseCharacter))
        {
            // 조합 문자가 아닌 경우 분해를 통해서 찾지 못하기 때문에 단일 문자 결과를 인용
            // If character is not combined, each letter can't decompose. so using single letter.
            baseFirstLetterIndex = _GetFirstHangulLetterIndex(baseCharacter);
            baseMiddleLetterIndex = _GetMiddleHangulLetterIndex(baseCharacter);
            baseLastLetterIndex = _ContainsFirstHangulLetterIndex(baseFirstLetterIndex) ? -1 : _GetLastHangulLetterIndex(baseCharacter);
        }
        else
        {
            // 기존 조합 문자를 분해하고 초성, 중성, 종성 별 인덱스 찾기
            // Decompose base character
            const size_t MIDDLE_LAST_STRIDE = MIDDLE_HANGUL_LETTERS_LENGTH * LAST_HANGUL_LETTERS_LENGTH;

            int baseUnicode = baseCharacter - HANGUL_CHARACTER_BEGIN;
            int baseFirstLetterRemainIndex = baseUnicode % (int)MIDDLE_LAST_STRIDE;

            baseFirstLetterIndex = baseUnicode / (int)MIDDLE_LAST_STRIDE;
            baseMiddleLetterIndex = baseFirstLetterRemainIndex / (int)LAST_HANGUL_LETTERS_LENGTH;
            baseLastLetterIndex = baseFirstLetterRemainIndex % (int)LAST_HANGUL_LETTERS_LENGTH;
        }

        bool baseFirstLetterExists = _ContainsFirstHangulLetterIndex(baseFirstLetterIndex);
        bool baseMiddleLetterExists = _ContainsMiddleHangulLetterIndex(baseMiddleLetterIndex);
        bool baseLastLetterExists = _ContainsLastHangulLetterIndex(baseLastLetterIndex);

        if (baseLastLetterExists)
        {
            wchar_t baseLastLetter = LAST_HANGUL_LETTERS[baseLastLetterIndex];

            wchar_t letter1 = '\0';
            wchar_t letter2 = '\0';

            if (_DecomposeDoubleConsonantHangulLetter(baseLastLetter, &letter1, &letter2))
            {
                baseLastLetterIndex = _GetLastHangulLetterIndex(letter1);
            }
            else if (flags & USE_COMPOSITION_DOUBLE_SAME_CONSONANT &&
                     _DecomposeDoubleSameConsonantHangulLetter(baseLastLetter, &letter1, &letter2))
            {
                baseLastLetterIndex = _GetLastHangulLetterIndex(letter1);
            }
            else
            {
                baseLastLetterIndex = -1;
            }

            goto DECOMPOSING;
        }

        if (baseMiddleLetterExists)
        {
            wchar_t baseMiddleLetter = MIDDLE_HANGUL_LETTERS[baseMiddleLetterIndex];

            wchar_t letter1 = '\0';
            wchar_t letter2 = '\0';

            if (_DecomposeDoubleVowelHangulLetter(baseMiddleLetter, &letter1, &letter2))
            {
                baseMiddleLetterIndex = _GetMiddleHangulLetterIndex(letter1);
            }
            else if (flags & USE_COMPOSITION_DOUBLE_LIGATURE_VOWEL &&
                     _DecomposeDoubleLigatureVowelHangulLetter(baseMiddleLetter, &letter1, &letter2))
            {
                baseMiddleLetterIndex = _GetMiddleHangulLetterIndex(letter1);
            }
            else
            {
                baseMiddleLetterIndex = -1;
            }

            goto DECOMPOSING;
        }

        if (baseFirstLetterExists)
        {
            wchar_t baseFirstLetter = FIRST_HANGUL_LETTERS[baseFirstLetterIndex];

            wchar_t letter1 = '\0';
            wchar_t letter2 = '\0';

            if (_DecomposeDoubleConsonantHangulLetter(baseFirstLetter, &letter1, &letter2))
            {
                baseFirstLetterIndex = _GetFirstHangulLetterIndex(letter1);
            }
            else if (flags & USE_COMPOSITION_DOUBLE_SAME_CONSONANT &&
                     _DecomposeDoubleSameConsonantHangulLetter(baseFirstLetter, &letter1, &letter2))
            {
                baseFirstLetterIndex = _GetFirstHangulLetterIndex(letter1);
            }
            else
            {
                baseFirstLetterIndex = -1;
            }


            baseFirstLetterIndex = -1;

            goto DECOMPOSING;
        }

        goto ESCAPE_DECOMPOSING;

    DECOMPOSING:
        // 모든 문자 조합
        // Compose letters
        baseCharacter = _ComposeHangulCharacter(baseFirstLetterIndex, baseMiddleLetterIndex, baseLastLetterIndex);

        if (baseCharacter != '\0')
        {
            _UpdateHangulContext(context, baseCharacter, true, HANGUL_COMPOSITION_IN);

            return true;
        }

    ESCAPE_DECOMPOSING:
        // 분해 할 수 없으므로 문자를 제거
        // Remove existing character directly because failed decompose
        _UpdateHangulContext(context, L'\0', false, HANGUL_COMPOSITION_REMOVE);

        return true;
    }

    return false;
}