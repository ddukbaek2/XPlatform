Get-ChildItem -Recurse -Include *.cpp,*.h | ForEach-Object {
    $content = Get-Content $_.FullName
    Set-Content -Encoding utf8 -Path $_.FullName -Value $content
}