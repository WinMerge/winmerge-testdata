/**
 * @brief Return installed or local version of 7-Zip.
 */
DWORD NTAPI VersionOf7z(BOOL bLocal)
{
	TCHAR path[MAX_PATH];
	if (bLocal)
	{
		GetModuleFileName(0, path, sizeof path/sizeof*path);
		PathRemoveFileSpec(path);
	}
	else
	{
		static const TCHAR szSubKey[] = _T("Software\\7-Zip");
		static const TCHAR szValue[] = _T("Path");
		DWORD type = 0;
		DWORD size = sizeof path;
		SHGetValue(HKEY_LOCAL_MACHINE, szSubKey, szValue, &type, path, &size);
	}
	PathAppend(path, _T("7zip_pad.xml"));
	CMarkdown::String version
	(
		CMarkdown::File(path)
		.Move("XML_DIZ_INFO").Pop()
		.Move("Program_Info").Pop()
		.Move("Program_Version").GetInnerText()
	);
	DWORD ver = (WORD)StrToIntA(version.A) << 16;
	if (LPSTR p = StrChrA(version.A, '.'))
	{
		ver |= (WORD)StrToIntA(p + 1);
	}
	return ver;
}
