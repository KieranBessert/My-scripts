$Hash = Get-FileHash "D:\IT 120\PS Scripts\Guide to the galaxy.ps1" -Algorithm MD5
$Hash.Hash >> "D:\IT 120\PS Scripts\File1.txt"
Get-Content -path "D:\IT 120\PS Scripts\File1.txt"

#Set-Content is the same as '>' which overwrites a file each time
#Add-Content is the same as '>>' which adds to the bottom of a file each time

#New-Item "file1.txt" -ItemType file 
