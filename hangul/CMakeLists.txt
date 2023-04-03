add_library (hangul STATIC "hangul.c")

SET(APP_NAME hangul-test)

ADD_EXECUTABLE(${APP_NAME} "hangul-test.c") 

TARGET_LINK_LIBRARIES(${APP_NAME} hangul)