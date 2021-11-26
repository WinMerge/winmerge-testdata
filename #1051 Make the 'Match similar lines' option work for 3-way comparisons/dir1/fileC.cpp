				std::vector<strdiff::wdiff> worddiffs = strdiff::ComputeWordDiffs(m_nBuffers, str,
					!diffOptions.bIgnoreCase,
					!diffOptions.bIgnoreEol,
					diffOptions.nIgnoreWhitespace,
					diffOptions.bIgnoreNumbers,
					GetBreakType(), // whitespace only or include punctuation
					GetByteColoringOption());
				if (!worddiffs.empty())
				{
					for (int file = 0; file < m_nBuffers; ++file)
						m_ptBuf[file]->SetLineFlag(i, LF_TRIVIAL, true, false, false);
				}
