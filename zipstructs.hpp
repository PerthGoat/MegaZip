#pragma once
#ifndef ZIPSTRUCTS
#define ZIPSTRUCTS

#include "common.hpp"

// structs for reading 32-bit zip data chunks

struct zip_header_32bit {
    uint32_t signature;         // signature of the header (should be 0x04034b50)
    uint16_t version_needed;    // minimum version needed to extract the file
    uint16_t flags;             // general purpose bit flags
    uint16_t compression_method;// compression method (e.g., deflate, store)
    uint16_t mod_time;          // last modification time (MS-DOS format)
    uint16_t mod_date;          // last modification date (MS-DOS format)
    uint32_t crc32;             // CRC-32 checksum of the uncompressed data
    uint32_t compressed_size;   // compressed size of the file
    uint32_t uncompressed_size; // uncompressed size of the file
    uint16_t filename_length;   // length of the filename
    uint16_t extra_length;      // length of extra data
};

struct zip_central_directory_32bit {
    uint32_t signature;             // signature of the central directory record (should be 0x02014b50)
    uint16_t version_made_by;       // version of the software used to create the zip file
    uint16_t version_needed;        // minimum version needed to extract the file
    uint16_t flags;                 // general purpose bit flags
    uint16_t compression_method;    // compression method (e.g., deflate, store)
    uint16_t mod_time;              // last modification time (MS-DOS format)
    uint16_t mod_date;              // last modification date (MS-DOS format)
    uint32_t crc32;                 // CRC-32 checksum of the uncompressed data
    uint32_t compressed_size;       // compressed size of the file
    uint32_t uncompressed_size;     // uncompressed size of the file
    uint16_t filename_length;       // length of the filename
    uint16_t extra_length;          // length of extra data
    uint16_t comment_length;        // length of the comment
    uint16_t disk_number_start;     // number of the disk on which this file starts
    uint16_t internal_file_attributes; // internal file attributes
    uint32_t external_file_attributes; // external file attributes
    uint32_t relative_offset;       // relative offset of the local header from the start of the archive
};

struct zip_end_of_central_directory_32bit {
    uint32_t signature;             // signature of the end of central directory record (should be 0x06054B50)
    uint16_t disk_number;           // number of the disk with the start of the central directory
    uint16_t disk_number_cd;        // number of the disk containing the central directory
    uint16_t num_entries_disk;      // number of central directory records on this disk
    uint16_t num_entries_total;     // total number of central directory records
    uint32_t size_of_cd;            // size of the central directory
    uint32_t offset_of_cd;          // offset of the start of the central directory
    uint16_t comment_length;        // length of the zip file comment
};


// structs for reading 64-bit zip data chunks

#define ZIP64_ENDOFCENTRALDIRLOC_SIG 0x07064b50

struct zip64_header {
    uint32_t signature;             // signature of the header (should be 0x04034b50)
    uint16_t version_needed;        // minimum version needed to extract the file
    uint16_t flags;                 // general purpose bit flags
    uint16_t compression_method;    // compression method (e.g., deflate, store)
    uint16_t mod_time;              // last modification time (MS-DOS format)
    uint16_t mod_date;              // last modification date (MS-DOS format)
    uint32_t crc32;                 // CRC-32 checksum of the uncompressed data
    uint64_t compressed_size;       // compressed size of the file (zip64 extension)
    uint64_t uncompressed_size;     // uncompressed size of the file (zip64 extension)
    uint16_t filename_length;       // length of the filename
    uint16_t extra_length;          // length of extra data
    uint16_t version_needed_zip64;  // version needed to extract the file (zip64 extension)
    uint16_t extra_field_zip64_len; // length of extra field (zip64 extension)
    uint64_t relative_offset;       // relative offset of the local header from the start of the archive (zip64 extension)
};

struct zip64_central_directory {
    uint32_t signature;             // signature of the central directory record (should be 0x02014b50)
    uint16_t version_made_by;       // version of the software used to create the zip file
    uint16_t version_needed;        // minimum version needed to extract the file
    uint16_t flags;                 // general purpose bit flags
    uint16_t compression_method;    // compression method (e.g., deflate, store)
    uint16_t mod_time;              // last modification time (MS-DOS format)
    uint16_t mod_date;              // last modification date (MS-DOS format)
    uint32_t crc32;                 // CRC-32 checksum of the uncompressed data
    uint64_t compressed_size;       // compressed size of the file (zip64 extension)
    uint64_t uncompressed_size;     // uncompressed size of the file (zip64 extension)
    uint16_t filename_length;       // length of the filename
    uint16_t extra_length;          // length of extra data
    uint16_t comment_length;        // length of the comment
    uint16_t disk_number_start;     // number of the disk on which this file starts
    uint16_t internal_file_attributes; // internal file attributes
    uint32_t external_file_attributes; // external file attributes
    uint64_t relative_offset;       // relative offset of the local header from the start of the archive (zip64 extension)
    uint16_t extra_field_zip64_len; // length of extra field (zip64 extension)
    uint16_t version_needed_zip64;  // version needed to extract the file (zip64 extension)
};

struct zip64_end_of_central_directory_locator {
    uint32_t signature;             // signature of the Zip64 end of central directory locator (should be 0x07064b50)
    uint32_t disk_number;           // number of the disk containing the Zip64 end of central directory record
    uint64_t offset_of_zip64_eocd;  // offset of the Zip64 end of central directory record relative to the starting disk number
    uint32_t num_disks;             // total number of disks in the archive
};

struct zip64_end_of_central_directory {
    uint32_t signature;              // signature of the Zip64 end of central directory record (should be 0x06064b50)
    uint64_t size_of_zip64_eocd;     // size of the Zip64 end of central directory record
    uint16_t version_made_by;        // version of the software used to create the archive
    uint16_t version_needed_to_extract; // minimum version of software needed to extract the archive
    uint32_t disk_number;            // number of the disk containing the start of the Zip64 end of central directory record
    uint32_t disk_number_cd;         // number of the disk containing the start of the central directory
    uint64_t num_entries_on_disk;    // number of central directory entries on this disk
    uint64_t num_entries_total;      // total number of central directory entries
    uint64_t size_of_cd;             // size of the central directory
    uint64_t offset_of_cd;           // offset of the start of the central directory relative to the starting disk number
};

#endif