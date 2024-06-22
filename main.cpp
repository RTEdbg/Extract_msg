/*
 * Copyright (c) 2024 Branko Premzel.
 *
 * SPDX-License-Identifier: MIT
 */

 /*******************************************************************************
 * @file    main.c
 * @author  B. Premzel
 * @brief   Extract_msg utility
 *          This utility is designed to prepare the messages.txt file with the 
 *          texts used during the execution of the RTEmsg application (error 
 *          reporting and information preparation).
 *          It extracts text strings from the input header file and writes them to
 *          the output file. The strings must be encloses between double quotes. 
 *          They must be after the "// " comment and no empty space is allowed 
 *          after the closing double quote.
 * @version 1.00
 ******************************************************************************/

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2000


int main(int argc, char * argv[])
{
    int line = 0;

    if (argc < 3)
    {
        fprintf(stderr,
            "Syntax:\n   Extract_msg input_header_file output_text_file"
            "\n\nSee Readme.md file in https://github.com/RTEdbg/Extract_msg project for instructions."
            "\nSoftware version: % s.\n",
            __DATE__
            );
        return 1;
    }

    errno_t errno;
    FILE * in_file;
    errno = fopen_s(&in_file, argv[1], "r");
    if (errno != 0)
    {
        fprintf(stderr, "Could not open the input file '%s'.", argv[1]);
        return 1;
    }

    FILE * out_file;
    errno = fopen_s(&out_file, argv[2], "w");
    if (errno != 0)
    {
        fprintf(stderr, "Could not open the output file '%s'.", argv[2]);
        return 1;
    }

    static char input_line[MAX_LINE_LENGTH];
    
    while (!feof(in_file))
    {
        fgets(input_line, MAX_LINE_LENGTH, in_file);
        line++;
        char * text = strstr(input_line, "// ");
        if (text != NULL)
        {
            size_t length = strlen(text);
            if ((text[length - 1] != '\n') || (text[length - 2] != '\"'))
            {
                // Print the error message so that Visual Studio IDE will recognize the file and line number
                fprintf(stderr, "Messages.h(%d): error 1: missing double qoute character at the end of text or surplus space characters before end of line", line);
                return 1;
            }
            text[length - 2] = 0;       // Strip off the " and newline at the end
            fputs(&text[4], out_file);  // Write text after the "
            fputc('\n', out_file);
        }
    }

    return 0;
}