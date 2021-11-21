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
	PathAppend(path, _T("7z.dll"));
	DWORD versionMS = 0;
	DWORD versionLS = 0;
	CVersionInfo(path).GetFixedFileVersion(versionMS, versionLS);
	return versionMS;
}
