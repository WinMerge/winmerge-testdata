void CImgMergeFrame::ChangeFile(int nBuffer, const String& path)
{
	if (!PromptAndSaveIfNeeded(true))
		return;

	for (int pane = 0; pane < m_pImgMergeWindow->GetPaneCount(); ++pane)
		RevokeDragDrop(m_pImgMergeWindow->GetPaneHWND(pane));

	m_filePaths[nBuffer] = path;
	m_nBufferType[nBuffer] = BUFFERTYPE::NORMAL;
	m_strDesc[nBuffer] = _T("");

	OpenImages();
	for (int pane = 0; pane < m_filePaths.GetSize(); ++pane)
		m_fileInfo[pane].Update(m_filePaths[pane]);

	UpdateHeaderPath(nBuffer);
	UpdateLastCompareResult();
}

