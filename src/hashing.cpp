#include <stdio.h>

#include <declares.h>
#include "bcrypt/BCrypt.hpp"

BSTR EXPORT CALLBACK HashPassword(char* RawPassword, uint8_t workload = 9) {
    #pragma UNDECORATE

    // Hasheamos la contraseña
    std::string hashedPassword = BCrypt::generateHash(RawPassword, workload);

    // Devolvemos la contraseña hasheada (std::string -> BSTR)
    return SysAllocStringByteLen(hashedPassword.c_str(), hashedPassword.size());
}

BOOL EXPORT CALLBACK VerifyPassword(char* RawPassword, char* HashedPassword) {
    #pragma UNDECORATE
    return BCrypt::validatePassword(RawPassword, HashedPassword);
}