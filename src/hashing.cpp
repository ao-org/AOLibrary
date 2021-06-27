#include <stdio.h>

#include <declares.h>
#include <util.h>

#include "bcrypt/BCrypt.hpp"

BSTR EXPORT CALLBACK HashPassword(LPSTR RawPassword) {
    #pragma UNDECORATE
    // Constraseña a hashear + BSTR -> std::string
    std::string inputPassword = bstr_to_string(RawPassword);
    
    // Hasheamos la contraseña
    std::string hashedPassword = BCrypt::generateHash(inputPassword);

    // Devolvemos la contraseña hasheada (std::string -> BSTR)
    return string_to_bstr(hashedPassword);
}

BOOL EXPORT CALLBACK VerifyPassword(LPSTR RawPassword, LPSTR HashedPassword) {
    #pragma UNDECORATE
    return BCrypt::validatePassword(bstr_to_string(RawPassword), bstr_to_string(HashedPassword));
}