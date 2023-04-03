#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <wchar.h> 

#pragma region Hangul Common Constants
#define USE_COMPOSITION_DOUBLE_LIGATURE_VOWEL       0b00000001
#define USE_COMPOSITION_DOUBLE_SAME_CONSONANT       0b00000010
#pragma endregion

#pragma region Enum and Structures
typedef enum _HANGUL_COMPOSITION_STATE
{
    HANGUL_COMPOSITION_START,
    HANGUL_COMPOSITION_IN,
    HANGUL_COMPOSITION_COMPLETE,
    HANGUL_COMPOSITION_NONE,
    HANGUL_COMPOSITION_REMOVE,
} HANGUL_COMPOSITION_STATE;

typedef void (*HANGUL_COMPOSITION_CALLBACK)(HANGUL_COMPOSITION_STATE state, wchar_t character);

typedef struct _HANGUL_CONTEXT
{
    wchar_t buffer;
    HANGUL_COMPOSITION_CALLBACK callback;

    bool combining;
} HANGUL_CONTEXT;
#pragma endregion

bool IsHangulLetter(const wchar_t character);

bool IsHangulCharacter(const wchar_t character);

bool IsHangul(const wchar_t character);

void InitializeHangulContext(HANGUL_CONTEXT* context, HANGUL_COMPOSITION_CALLBACK callback);

void ComposeHangulCharacter(HANGUL_CONTEXT* context, const wchar_t typed, unsigned char flags);

bool DecomposeHangulCharacter(HANGUL_CONTEXT* context, unsigned char flags);