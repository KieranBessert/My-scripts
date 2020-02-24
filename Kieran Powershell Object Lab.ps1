#Created by Kieran Bessert | edited 2/28/2019
Write-Host "Please wait, currently finding all DLLs."
#Set variable and conduct recursive search
$dllCOUNT = get-ChildItem -Path C:\Windows -Recurse -Include *.dll -file -ErrorAction silentlycontinue 
write-host "You have "$dllCOUNT.count" in your C:\Windows directory."
#wait
Start-Sleep 3
Write-Host "Please wait while CSV is generated."
#wait
Start-Sleep 3
#takes last 100 lines and exports to csv
$dllCOUNT | Select-Object -Last 100 | Export-Csv -LiteralPath C:\Users\$env:USERNAME\Documents\dll.csv
Write-Host "Complete."

