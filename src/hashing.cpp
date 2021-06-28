#include <stdio.h>

#include <declares.h>
#include <util.h>

#include "bcrypt/BCrypt.hpp"

BSTR EXPORT CALLBACK HashPassword(char* RawPassword) {
    #pragma UNDECORATE
    // Constraseña a hashear    
    // Hasheamos la contraseña
    std::string hashedPassword = BCrypt::generateHash(RawPassword, 9);

    // Devolvemos la contraseña hasheada (std::string -> BSTR)
    return SysAllocStringByteLen(hashedPassword.c_str(), hashedPassword.size());
}

BOOL EXPORT CALLBACK VerifyPassword(char* RawPassword, char* HashedPassword) {
    #pragma UNDECORATE
    return BCrypt::validatePassword(RawPassword, HashedPassword);
}