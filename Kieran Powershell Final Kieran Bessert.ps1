<#Created by Kieran Bessert last updated 19March2018

Script was written with this folder structure:

C:\users\$env:USERNAME\Documents\FINAL\$files

script WILL NOT run if there is no FINAL folder (containing the txt/md5 files) in the user's documents folder#>

#set variable count to 0
$count = 0


    #First fetch list of our txt files we want to check (excluding future invalid file) and put that output into a variable
$txtFiles = Get-ChildItem C:\Users\$env:USERNAME\Documents\final -exclude "*md5", "invalid*"

    #now for each of those lines, strip it down to just the name and start a loop of commands
foreach($txt in $txtFiles.name){

        #generate an MD5 hash for the file and store it in a variable
    $txtHASH = Get-FileHash C:\users\$env:USERNAME\Documents\final\$txt -Algorithm MD5
        
        #locate the matching MD5 file and unpack its contents into a variable  
    $md5File = $txt -replace "txt","md5"
    $md5HASH = Get-Content C:\users\$env:USERNAME\Documents\final\$md5File
    
            #compare the 2 varialbes we have filled in the loop 
        if ($txtHASH.hash -ne $md5HASH) {
            
                <#if the variables don't match, the txt file has been altered from the original hash.
                  The user is warned, while the file name and time is recorded in invalid.txt#>  
            Write-warning "Invalid file: $txt"
            $time = Get-Date
            Add-Content -value $time.DateTime -Path C:\users\$env:USERNAME\Documents\final\Invalid.txt 
            Add-Content -value $txt -Path C:\users\$env:USERNAME\Documents\final\Invalid.txt
            $count = $count + 1
        }
            <#if they didn't fail to match, then that must mean they did match.
              The user is bonked to affirm file has been unchanged#>
        else {
            Write-Host "Bonk $txt" -ForegroundColor Green
        }}
        
    #tell the user the script is complete and how many invalid files total they recieved
Start-Sleep 1
Write-Host "File check complete; $count invalid files"
Write-Host "Invalid files recorded in;"
Write-Host "C:\users\$env:USERNAME\Documents\final\Invalid.txt" -ForegroundColor Yellow