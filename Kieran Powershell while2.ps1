$myProcess = Get-Process | Where-Object {$_.name -like "Chrome"}
Write-Host $myProcess.id -ForegroundColor Cyan