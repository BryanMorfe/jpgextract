# jpgextract
Extract All JPG images from a file.

## Description
jpgextract allows you to extract all the jpg images in a file. Some devices cache multiple jpg images in a single file (such as Android devices), and this software pulls out all the jpg images it finds. You can also use it to extract jpg images from a drive partition.

This software is very beta. It was coded because I needed a program that did just that. It saves all the jpg images it finds as 0.jpg, 1.jpg, ... n.jpg.

## Usage
`$ jpgextract filename`

## Work In Progress
I am working on `mediaextract` a more general purpose command line tool that allows you to extract various types of files such a jpg, png, mp4, gif, etc. I will keep you posted here. In the meantime, you are free to use this version (with no guarantees), as stated in the license.

## Installation
No makefile is provided, so for a quick installation just run:

`$ gcc jpegextract.c -o jpgextract && sudo cp jpgextract path/to/bin/jpgextract`

The path to bin directory depends on your system. In my system (Mac), I installed it in `/opt/local/bin/jpgextract`

