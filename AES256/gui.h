#include<Windows.h>
#include<wincrypt.h>
#include<msclr\marshal_windows.h>

#pragma once

int selectfile = 1;
int removefile = 0;

int show = 1;
int hide = 0;

#define ENCRYPTION_ALGORITHM CALG_AES_256
#define BLOCK_SIZE 64

namespace AES256
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class gui : public System::Windows::Forms::Form
	{
		public:
			gui(void)
			{
				InitializeComponent();
			}
		protected:
			~gui()
			{
				if (components)
				{
					delete components;
				}
			}
			private: System::Windows::Forms::Label^  label1;
			protected: 
			private: System::Windows::Forms::Label^  label2;
			private: System::Windows::Forms::Label^  label3;
			private: System::Windows::Forms::TextBox^  textBox1;
			private: System::Windows::Forms::TextBox^  textBox2;
			private: System::Windows::Forms::RadioButton^  radioButton1;
			private: System::Windows::Forms::RadioButton^  radioButton2;
			private: System::Windows::Forms::Button^  button1;
			private: System::Windows::Forms::Button^  button2;
			private: System::Windows::Forms::Button^  button3;
			private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
			private: Microsoft::VisualBasic::PowerPacks::ShapeContainer^  shapeContainer1;
			private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  rectangleShape4;
			private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  rectangleShape3;
			private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  rectangleShape2;
			private: Microsoft::VisualBasic::PowerPacks::RectangleShape^  rectangleShape1;
			private: System::Windows::Forms::Label^  label4;
			private: System::Windows::Forms::TextBox^  textBox3;
			private: System::Windows::Forms::LinkLabel^  linkLabel1;
			private: System::ComponentModel::IContainer^  components;
			private:	
				#pragma region Windows Form Designer generated code
				void InitializeComponent(void)
				{
					this->label1 = (gcnew System::Windows::Forms::Label());
					this->label2 = (gcnew System::Windows::Forms::Label());
					this->label3 = (gcnew System::Windows::Forms::Label());
					this->textBox1 = (gcnew System::Windows::Forms::TextBox());
					this->textBox2 = (gcnew System::Windows::Forms::TextBox());
					this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
					this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
					this->button1 = (gcnew System::Windows::Forms::Button());
					this->button2 = (gcnew System::Windows::Forms::Button());
					this->button3 = (gcnew System::Windows::Forms::Button());
					this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
					this->shapeContainer1 = (gcnew Microsoft::VisualBasic::PowerPacks::ShapeContainer());
					this->rectangleShape4 = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
					this->rectangleShape3 = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
					this->rectangleShape2 = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
					this->rectangleShape1 = (gcnew Microsoft::VisualBasic::PowerPacks::RectangleShape());
					this->label4 = (gcnew System::Windows::Forms::Label());
					this->textBox3 = (gcnew System::Windows::Forms::TextBox());
					this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
					this->SuspendLayout();
					// 
					// label1
					// 
					this->label1->AutoSize = true;
					this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->label1->Location = System::Drawing::Point(23, 9);
					this->label1->Name = L"label1";
					this->label1->Size = System::Drawing::Size(54, 13);
					this->label1->TabIndex = 0;
					this->label1->Text = L"File Name";
					// 
					// label2
					// 
					this->label2->AutoSize = true;
					this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->label2->Location = System::Drawing::Point(23, 85);
					this->label2->Name = L"label2";
					this->label2->Size = System::Drawing::Size(53, 13);
					this->label2->TabIndex = 1;
					this->label2->Text = L"Password";
					// 
					// label3
					// 
					this->label3->AutoSize = true;
					this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->label3->Location = System::Drawing::Point(23, 162);
					this->label3->Name = L"label3";
					this->label3->Size = System::Drawing::Size(48, 13);
					this->label3->TabIndex = 2;
					this->label3->Text = L"Function";
					// 
					// textBox1
					// 
					this->textBox1->CausesValidation = false;
					this->textBox1->Enabled = false;
					this->textBox1->Location = System::Drawing::Point(26, 37);
					this->textBox1->Name = L"textBox1";
					this->textBox1->Size = System::Drawing::Size(183, 20);
					this->textBox1->TabIndex = 3;
					// 
					// textBox2
					// 
					this->textBox2->CausesValidation = false;
					this->textBox2->Enabled = false;
					this->textBox2->Location = System::Drawing::Point(26, 111);
					this->textBox2->Name = L"textBox2";
					this->textBox2->Size = System::Drawing::Size(183, 20);
					this->textBox2->TabIndex = 4;
					this->textBox2->UseSystemPasswordChar = true;
					this->textBox2->TextChanged += gcnew System::EventHandler(this, &gui::textBox2_TextChanged);
					// 
					// radioButton1
					// 
					this->radioButton1->AutoSize = true;
					this->radioButton1->Enabled = false;
					this->radioButton1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->radioButton1->Location = System::Drawing::Point(26, 190);
					this->radioButton1->Name = L"radioButton1";
					this->radioButton1->Size = System::Drawing::Size(61, 17);
					this->radioButton1->TabIndex = 5;
					this->radioButton1->Text = L"Encrypt";
					this->radioButton1->UseVisualStyleBackColor = true;
					this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &gui::radioButton1_CheckedChanged);
					// 
					// radioButton2
					// 
					this->radioButton2->AutoSize = true;
					this->radioButton2->Enabled = false;
					this->radioButton2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->radioButton2->Location = System::Drawing::Point(147, 190);
					this->radioButton2->Name = L"radioButton2";
					this->radioButton2->Size = System::Drawing::Size(62, 17);
					this->radioButton2->TabIndex = 6;
					this->radioButton2->Text = L"Decrypt";
					this->radioButton2->UseVisualStyleBackColor = true;
					this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &gui::radioButton2_CheckedChanged);
					// 
					// button1
					// 
					this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->button1->Location = System::Drawing::Point(215, 35);
					this->button1->Name = L"button1";
					this->button1->Size = System::Drawing::Size(75, 23);
					this->button1->TabIndex = 9;
					this->button1->Text = L"Select File";
					this->button1->UseVisualStyleBackColor = true;
					this->button1->Click += gcnew System::EventHandler(this, &gui::button1_Click);
					// 
					// button2
					// 
					this->button2->Enabled = false;
					this->button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->button2->Location = System::Drawing::Point(215, 109);
					this->button2->Name = L"button2";
					this->button2->Size = System::Drawing::Size(75, 23);
					this->button2->TabIndex = 10;
					this->button2->Text = L"Show";
					this->button2->UseVisualStyleBackColor = true;
					this->button2->Click += gcnew System::EventHandler(this, &gui::button2_Click);
					// 
					// button3
					// 
					this->button3->Enabled = false;
					this->button3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->button3->Location = System::Drawing::Point(215, 187);
					this->button3->Name = L"button3";
					this->button3->Size = System::Drawing::Size(75, 23);
					this->button3->TabIndex = 11;
					this->button3->Text = L"Go";
					this->button3->UseVisualStyleBackColor = true;
					this->button3->Click += gcnew System::EventHandler(this, &gui::button3_Click);
					// 
					// shapeContainer1
					// 
					this->shapeContainer1->Location = System::Drawing::Point(0, 0);
					this->shapeContainer1->Margin = System::Windows::Forms::Padding(0);
					this->shapeContainer1->Name = L"shapeContainer1";
					this->shapeContainer1->Shapes->AddRange(gcnew cli::array< Microsoft::VisualBasic::PowerPacks::Shape^  >(4) {this->rectangleShape4, 
						this->rectangleShape3, this->rectangleShape2, this->rectangleShape1});
					this->shapeContainer1->Size = System::Drawing::Size(316, 409);
					this->shapeContainer1->TabIndex = 12;
					this->shapeContainer1->TabStop = false;
					// 
					// rectangleShape4
					// 
					this->rectangleShape4->BorderColor = System::Drawing::SystemColors::AppWorkspace;
					this->rectangleShape4->Enabled = false;
					this->rectangleShape4->Location = System::Drawing::Point(15, 245);
					this->rectangleShape4->Name = L"rectangleShape4";
					this->rectangleShape4->Size = System::Drawing::Size(286, 142);
					// 
					// rectangleShape3
					// 
					this->rectangleShape3->BorderColor = System::Drawing::SystemColors::AppWorkspace;
					this->rectangleShape3->Enabled = false;
					this->rectangleShape3->Location = System::Drawing::Point(15, 169);
					this->rectangleShape3->Name = L"rectangleShape3";
					this->rectangleShape3->Size = System::Drawing::Size(286, 59);
					// 
					// rectangleShape2
					// 
					this->rectangleShape2->BorderColor = System::Drawing::SystemColors::AppWorkspace;
					this->rectangleShape2->Enabled = false;
					this->rectangleShape2->Location = System::Drawing::Point(15, 92);
					this->rectangleShape2->Name = L"rectangleShape2";
					this->rectangleShape2->Size = System::Drawing::Size(286, 59);
					// 
					// rectangleShape1
					// 
					this->rectangleShape1->BorderColor = System::Drawing::SystemColors::AppWorkspace;
					this->rectangleShape1->Enabled = false;
					this->rectangleShape1->Location = System::Drawing::Point(14, 16);
					this->rectangleShape1->Name = L"rectangleShape1";
					this->rectangleShape1->Size = System::Drawing::Size(286, 59);
					// 
					// label4
					// 
					this->label4->AutoSize = true;
					this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->label4->Location = System::Drawing::Point(23, 238);
					this->label4->Name = L"label4";
					this->label4->Size = System::Drawing::Size(25, 13);
					this->label4->TabIndex = 13;
					this->label4->Text = L"Log";
					// 
					// textBox3
					// 
					this->textBox3->BackColor = System::Drawing::Color::White;
					this->textBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
					this->textBox3->HideSelection = false;
					this->textBox3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->textBox3->Location = System::Drawing::Point(26, 264);
					this->textBox3->Multiline = true;
					this->textBox3->Name = L"textBox3";
					this->textBox3->ReadOnly = true;
					this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
					this->textBox3->Size = System::Drawing::Size(264, 103);
					this->textBox3->TabIndex = 14;
					// 
					// linkLabel1
					// 
					this->linkLabel1->ActiveLinkColor = System::Drawing::Color::Black;
					this->linkLabel1->AutoSize = true;
					this->linkLabel1->Cursor = System::Windows::Forms::Cursors::Hand;
					this->linkLabel1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
					this->linkLabel1->LinkBehavior = System::Windows::Forms::LinkBehavior::NeverUnderline;
					this->linkLabel1->LinkColor = System::Drawing::Color::Black;
					this->linkLabel1->Location = System::Drawing::Point(105, 392);
					this->linkLabel1->Name = L"linkLabel1";
					this->linkLabel1->Size = System::Drawing::Size(104, 13);
					this->linkLabel1->TabIndex = 15;
					this->linkLabel1->TabStop = true;
					this->linkLabel1->Text = L"The Boring Software";
					this->linkLabel1->VisitedLinkColor = System::Drawing::Color::Black;
					this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &gui::linkLabel1_LinkClicked);
					// 
					// gui
					// 
					this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->ClientSize = System::Drawing::Size(316, 409);
					this->Controls->Add(this->linkLabel1);
					this->Controls->Add(this->textBox3);
					this->Controls->Add(this->label4);
					this->Controls->Add(this->button3);
					this->Controls->Add(this->button2);
					this->Controls->Add(this->button1);
					this->Controls->Add(this->radioButton2);
					this->Controls->Add(this->radioButton1);
					this->Controls->Add(this->textBox2);
					this->Controls->Add(this->textBox1);
					this->Controls->Add(this->label3);
					this->Controls->Add(this->label2);
					this->Controls->Add(this->label1);
					this->Controls->Add(this->shapeContainer1);
					this->MaximizeBox = false;
					this->MaximumSize = System::Drawing::Size(332, 448);
					this->MinimumSize = System::Drawing::Size(332, 448);
					this->Name = L"gui";
					this->ShowIcon = false;
					this->Text = L"AES256";
					this->ResumeLayout(false);
					this->PerformLayout();

				}
			#pragma endregion
			private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			{	
				if(selectfile == 1)
				{
					openFileDialog1->InitialDirectory = L"C:\\";
					openFileDialog1->FileName = L"";
					openFileDialog1->Filter = L"All files | *.*";
					if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						String^ sourcefilename = System::IO::Path::GetFileName(openFileDialog1->FileName);
						textBox1->Text = sourcefilename;
						button1->Text = L"Remove File";
						selectfile = 0;
						removefile = 1;
						textBox2->Enabled = true;
					}
					else
					{					
					}
				}
				else
				{
					if(removefile == 1)
					{
						textBox1->Text = L"";
						button1->Text = L"Select File";
						selectfile = 1;
						removefile = 0;
						textBox2->Text = L"";
						textBox2->Enabled = false;
						button2->Enabled = false;
						radioButton1->Checked = false;
						radioButton1->Enabled = false;
						radioButton2->Checked = false;
						radioButton2->Enabled = false;
						button3->Enabled = false;
					}
					else
					{	
					}
				}
			}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if(show == 1)
			{	
					textBox2->UseSystemPasswordChar = false;
					button2->Text = L"Hide";
					show = 0;
					hide = 1;
			}
			else
			{
				if(hide == 1)
				{
					textBox2->UseSystemPasswordChar = true;
					button2->Text = L"Show";
					show = 1;
					hide = 0;
				}
				else
				{
				}
			}
		}
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		{	
			if(radioButton1->Checked)
			{
				button1->Enabled = false;
				textBox2->Enabled = false;
				try
				{
					textBox2->UseSystemPasswordChar = true;
				}
				finally
				{
				}
				button2->Enabled = false;
				radioButton1->Enabled = false;
				radioButton2->Enabled = false;
				button3->Enabled = false;
				HCRYPTPROV provider;
				CryptAcquireContext(&provider, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, CRYPT_VERIFYCONTEXT);
				HCRYPTHASH hash;
				CryptCreateHash(provider, CALG_SHA_256, NULL, NULL, &hash);
				marshal_context^ context = gcnew marshal_context();
				LPTSTR password = context->marshal_as<LPTSTR>(textBox2->Text);	
				textBox3->AppendText(L"\n*** Started ***\r\n");
				textBox3->AppendText(L"Hashing the password.\r\n");
				CryptHashData(hash, (BYTE*)password, lstrlen(password), NULL);
				HCRYPTKEY encryptionkey;
				textBox3->AppendText(L"Deriving an key from the password hash.\r\n");
				CryptDeriveKey(provider, ENCRYPTION_ALGORITHM, hash, NULL, &encryptionkey);
				HANDLE opensourcefile;
				String^ sourcefilepath = System::IO::Path::GetFullPath(openFileDialog1->FileName);
				LPCWSTR sourcefile = context->marshal_as<LPCWSTR>(sourcefilepath);
				textBox3->AppendText(L"Opening a source file.\r\n");
				opensourcefile = CreateFile(sourcefile, FILE_READ_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				DWORD bytes;
				bytes = 1000 - 1000 % BLOCK_SIZE; 
				DWORD bufferlength;
				if(BLOCK_SIZE > 1) 
				{
					bufferlength = bytes + BLOCK_SIZE; 
				}
				else 
				{
					bufferlength = bytes; 
				}
				PBYTE buffer;
				buffer = (BYTE*)malloc(bufferlength);
				String^ sourcefilenamewithextension = System::IO::Path::GetFileName(sourcefilepath);
				String^ sourcefilenamewithoutextension = System::IO::Path::GetFileNameWithoutExtension(sourcefilepath);
				String^ destinationfilepath = System::IO::Path::GetFullPath(sourcefilepath->Replace(sourcefilenamewithextension, sourcefilenamewithoutextension));
				LPCWSTR destinationfile = context->marshal_as<LPCWSTR>(destinationfilepath);
				HANDLE createdestinationfile;
				textBox3->AppendText(L"Creating a destination file.\r\n");
				createdestinationfile = CreateFile(destinationfile, FILE_WRITE_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
				textBox3->AppendText(L"Encrypting.\r\n");
				bool endoffile = FALSE;
				do 
				{
					DWORD count;
					ReadFile(opensourcefile, buffer, bytes, &count, NULL);
					if(count < bytes)
					{
						endoffile = TRUE;		
					}
					else
					{
					}
					CryptEncrypt(encryptionkey, NULL, endoffile, NULL, buffer, &count, bufferlength);
					WriteFile(createdestinationfile, buffer, count, &count, NULL);
				}
				while(!endoffile);
				CloseHandle(opensourcefile);
				free(buffer);
				CryptReleaseContext(provider, 0);
				CryptDestroyHash(hash);
				delete context;
				CryptDestroyKey(encryptionkey);
				CloseHandle(createdestinationfile);
				String^ sourcefileextension = System::IO::Path::GetExtension(sourcefilepath);
				String^ changefileextension = System::IO::Path::ChangeExtension(destinationfilepath, sourcefileextension);
				textBox3->AppendText(L"Removing source file.\r\n");
				System::IO::File::Delete(sourcefilepath);
				System::IO::File::Move(destinationfilepath, changefileextension);
				textBox3->AppendText(L"Encrypted.\r\n");
				textBox3->AppendText(L"\n*** Ended ***\r");
				textBox1->Text = L"";
				button1->Enabled = true;
				button1->Text = L"Select File";
				selectfile = 1;
				textBox2->Text = L"";
				try
				{
					radioButton1->Checked = false;
				}
				finally
				{	
				}
				try
				{
					radioButton2->Checked = false;
				}
				finally
				{
				}
			}
			else
			{
				if(radioButton2->Checked)
				{
					button1->Enabled = false;
					textBox2->Enabled = false;
					try
					{
						textBox2->UseSystemPasswordChar = true;
					}
					finally
					{
					}
					button2->Enabled = false;
					radioButton1->Enabled = false;
					radioButton2->Enabled = false;
					button3->Enabled = false;
					HCRYPTPROV provider;
					CryptAcquireContext(&provider, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, CRYPT_VERIFYCONTEXT);
					HCRYPTHASH hash;
					CryptCreateHash(provider, CALG_SHA_256, NULL, NULL, &hash);
					marshal_context^ context = gcnew marshal_context();
					LPTSTR password = context->marshal_as<LPTSTR>(textBox2->Text);	
					textBox3->AppendText(L"\n*** Started ***\r\n");
					textBox3->AppendText(L"Hashing the password.\r\n");
					CryptHashData(hash, (BYTE*)password, lstrlen(password), NULL);
					HCRYPTKEY encryptionkey;
					textBox3->AppendText(L"Deriving an key from the password hash.\r\n");
					CryptDeriveKey(provider, ENCRYPTION_ALGORITHM, hash, NULL, &encryptionkey);
					HANDLE opensourcefile;
					String^ sourcefilepath = System::IO::Path::GetFullPath(openFileDialog1->FileName);
					LPCWSTR sourcefile = context->marshal_as<LPCWSTR>(sourcefilepath);
					textBox3->AppendText(L"Opening a source file.\r\n");
					opensourcefile = CreateFile(sourcefile, FILE_READ_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					DWORD bytes;
					bytes = 1000 - 1000 % BLOCK_SIZE; 
					DWORD bufferlength;
					if(BLOCK_SIZE > 1) 
					{
						bufferlength = bytes + BLOCK_SIZE; 
					}
					else 
					{
						bufferlength = bytes; 
					}
					PBYTE buffer;
					buffer = (BYTE*)malloc(bufferlength);
					String^ sourcefilenamewithextension = System::IO::Path::GetFileName(sourcefilepath);
					String^ sourcefilenamewithoutextension = System::IO::Path::GetFileNameWithoutExtension(sourcefilepath);
					String^ destinationfilepath = System::IO::Path::GetFullPath(sourcefilepath->Replace(sourcefilenamewithextension, sourcefilenamewithoutextension));
					LPCWSTR destinationfile = context->marshal_as<LPCWSTR>(destinationfilepath);
					HANDLE createdestinationfile;
					textBox3->AppendText(L"Creating a destination file.\r\n");
					createdestinationfile = CreateFile(destinationfile, FILE_WRITE_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
					textBox3->AppendText(L"Decrypting.\r\n");
					bool endoffile = FALSE;
					int decryptionfailed;
					int decryptionsucess;
					do 
					{
						DWORD count;
						ReadFile(opensourcefile, buffer, bytes, &count, NULL);
						if(count < bytes)
						{
							endoffile = TRUE;		
						}
						else
						{
						}
						if(!CryptDecrypt(encryptionkey, NULL, endoffile, NULL, buffer, &count))
						{
							decryptionfailed = 1;
							break;		
						}
						WriteFile(createdestinationfile, buffer, count, &count, NULL);
					}
					while(!endoffile);
					decryptionsucess = 1;
					if(decryptionfailed == 1)
					{
						CloseHandle(opensourcefile);
						free(buffer);
						CryptReleaseContext(provider, 0);
						CryptDestroyHash(hash);
						delete context;
						CryptDestroyKey(encryptionkey);
						CloseHandle(createdestinationfile);
						textBox3->AppendText(L"Removing destination file.\r\n");
						System::IO::File::Delete(destinationfilepath);
						textBox3->AppendText(L"Decryption failed.\r\n");
						textBox3->AppendText(L"\n*** Ended ***\r");
						textBox1->Text = L"";
						button1->Enabled = true;
						button1->Text = L"Select File";
						selectfile = 1;
						textBox2->Text = L"";
						try
						{
							radioButton1->Checked = false;
						}
						finally
						{	
						}
						try
						{
							radioButton2->Checked = false;
						}
						finally
						{
						}
					}
					else
					{
						if(decryptionsucess == 1)
						{
							CloseHandle(opensourcefile);
							free(buffer);
							CryptReleaseContext(provider, 0);
							CryptDestroyHash(hash);
							delete context;
							CryptDestroyKey(encryptionkey);
							CloseHandle(createdestinationfile);
							String^ sourcefileextension = System::IO::Path::GetExtension(sourcefilepath);
							String^ changefileextension = System::IO::Path::ChangeExtension(destinationfilepath, sourcefileextension);
							textBox3->AppendText(L"Removing source file.\r\n");
							System::IO::File::Delete(sourcefilepath);
							System::IO::File::Move(destinationfilepath, changefileextension);
							textBox3->AppendText(L"Decrypted.\r\n");
							textBox3->AppendText(L"\n*** Ended ***\r");
							textBox1->Text = L"";
							button1->Enabled = true;
							button1->Text = L"Select File";
							selectfile = 1;
							textBox2->Text = L"";
							try
							{
								radioButton1->Checked = false;
							}
							finally
							{	
							}
							try
							{
								radioButton2->Checked = false;
							}
							finally
							{
							}
						}
						else
						{	
						}
					}
				}
			}
		}
		private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			button3->Enabled = true;
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		{
			button3->Enabled = true;
		}
		private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(textBox2->Text == L"")
				 {
					button2->Text = L"Show";
					textBox2->UseSystemPasswordChar = true;
					show = 1;
					button2->Enabled = false;
					radioButton1->Enabled = false;
					radioButton1->Checked = false;
					radioButton2->Enabled = false;
					radioButton2->Checked = false;
					button3->Enabled = false;
				 }
				 else
				 {
				        button2->Enabled = true;
					radioButton1->Enabled = true;
					radioButton2->Enabled = true;
				 }
			 }
	        private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
		{
		       System::Diagnostics::Process::Start("msedge", "https://github.com/TheBoringSoftware/AES256");
		}
	};
}
