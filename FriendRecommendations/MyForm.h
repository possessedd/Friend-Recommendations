#pragma once
namespace pr17_CLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			graph = gcnew Dictionary<String^, List<String^>^>();

			comboBoxUser1->DropDownStyle = ComboBoxStyle::DropDownList;
			comboBoxUser2->DropDownStyle = ComboBoxStyle::DropDownList;
			comboBoxSelectUser->DropDownStyle = ComboBoxStyle::DropDownList;

		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	private: System::Windows::Forms::Label^ labelUsers;
	private: System::Windows::Forms::ListBox^ listBoxUsers;
	private: System::Windows::Forms::TextBox^ textBoxUser;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonRename;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ comboBoxUser2;
	private: System::Windows::Forms::Label^ selectTwoUsers;
	private: System::Windows::Forms::ComboBox^ comboBoxUser1;
	private: System::Windows::Forms::Button^ buttonAddFriendship;



	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ListBox^ listBoxRecommendations;
	private: System::Windows::Forms::ComboBox^ comboBoxSelectUser;
	private: System::Windows::Forms::Button^ buttonShowRecommendations;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::Container^ components;
	private: Dictionary<String^, List<String^>^>^ graph;
	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		AddUserToGraph(textBoxUser->Text->Trim());
		textBoxUser->Clear();
	}
	private: System::Void buttonAddFriendship_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBoxUser1->SelectedItem == nullptr || comboBoxUser2->SelectedItem == nullptr)
			return;

		String^ user1 = comboBoxUser1->SelectedItem->ToString();
		String^ user2 = comboBoxUser2->SelectedItem->ToString();

		AddFriendshipToGraph(user1, user2);
	}
	private: System::Void buttonShowRecommendations_Click(System::Object^ sender, System::EventArgs^ e) {
		if (comboBoxSelectUser->SelectedItem == nullptr)
			return;

		String^ user = comboBoxSelectUser->SelectedItem->ToString();
		ShowRecommendationsFor(user);
	}
	private: System::Void buttonRename_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listBoxUsers->SelectedItem == nullptr)
			return;

		String^ oldName = listBoxUsers->SelectedItem->ToString();
		String^ newName = textBoxUser->Text->Trim();
		
		RenameUserInGraph(oldName, newName);
		textBoxUser->Clear();
		   }
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listBoxUsers->SelectedItem == nullptr)
			return;

		String^ user = listBoxUsers->SelectedItem->ToString();
		DeleteUserFromGraph(user);
	}

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->labelUsers = (gcnew System::Windows::Forms::Label());
			this->listBoxUsers = (gcnew System::Windows::Forms::ListBox());
			this->textBoxUser = (gcnew System::Windows::Forms::TextBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonRename = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBoxUser1 = (gcnew System::Windows::Forms::ComboBox());
			this->buttonAddFriendship = (gcnew System::Windows::Forms::Button());
			this->comboBoxUser2 = (gcnew System::Windows::Forms::ComboBox());
			this->selectTwoUsers = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->listBoxRecommendations = (gcnew System::Windows::Forms::ListBox());
			this->comboBoxSelectUser = (gcnew System::Windows::Forms::ComboBox());
			this->buttonShowRecommendations = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelUsers
			// 
			this->labelUsers->AutoSize = true;
			this->labelUsers->BackColor = System::Drawing::SystemColors::Control;
			this->labelUsers->ForeColor = System::Drawing::SystemColors::ControlText;
			this->labelUsers->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelUsers->Location = System::Drawing::Point(12, 18);
			this->labelUsers->Name = L"labelUsers";
			this->labelUsers->Size = System::Drawing::Size(34, 13);
			this->labelUsers->TabIndex = 2;
			this->labelUsers->Text = L"Users";
			// 
			// listBoxUsers
			// 
			this->listBoxUsers->FormattingEnabled = true;
			this->listBoxUsers->Location = System::Drawing::Point(15, 34);
			this->listBoxUsers->Name = L"listBoxUsers";
			this->listBoxUsers->Size = System::Drawing::Size(343, 303);
			this->listBoxUsers->TabIndex = 3;
			// 
			// textBoxUser
			// 
			this->textBoxUser->Location = System::Drawing::Point(15, 349);
			this->textBoxUser->Name = L"textBoxUser";
			this->textBoxUser->Size = System::Drawing::Size(100, 20);
			this->textBoxUser->TabIndex = 4;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(121, 346);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 5;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Location = System::Drawing::Point(202, 346);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(75, 23);
			this->buttonDelete->TabIndex = 6;
			this->buttonDelete->Text = L"Delete";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
			// 
			// buttonRename
			// 
			this->buttonRename->Location = System::Drawing::Point(283, 346);
			this->buttonRename->Name = L"buttonRename";
			this->buttonRename->Size = System::Drawing::Size(75, 23);
			this->buttonRename->TabIndex = 7;
			this->buttonRename->Text = L"Rename";
			this->buttonRename->UseVisualStyleBackColor = true;
			this->buttonRename->Click += gcnew System::EventHandler(this, &MyForm::buttonRename_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBoxUser1);
			this->groupBox1->Controls->Add(this->buttonAddFriendship);
			this->groupBox1->Controls->Add(this->comboBoxUser2);
			this->groupBox1->Controls->Add(this->selectTwoUsers);
			this->groupBox1->Location = System::Drawing::Point(388, 34);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(278, 156);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Friendship";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// comboBoxUser1
			// 
			this->comboBoxUser1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxUser1->FormattingEnabled = true;
			this->comboBoxUser1->Location = System::Drawing::Point(6, 32);
			this->comboBoxUser1->Name = L"comboBoxUser1";
			this->comboBoxUser1->Size = System::Drawing::Size(121, 21);
			this->comboBoxUser1->TabIndex = 3;
			// 
			// buttonAddFriendship
			// 
			this->buttonAddFriendship->Location = System::Drawing::Point(187, 130);
			this->buttonAddFriendship->Name = L"buttonAddFriendship";
			this->buttonAddFriendship->Size = System::Drawing::Size(85, 20);
			this->buttonAddFriendship->TabIndex = 2;
			this->buttonAddFriendship->Text = L"Add friendship";
			this->buttonAddFriendship->UseVisualStyleBackColor = true;
			this->buttonAddFriendship->Click += gcnew System::EventHandler(this, &MyForm::buttonAddFriendship_Click);
			// 
			// comboBoxUser2
			// 
			this->comboBoxUser2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxUser2->FormattingEnabled = true;
			this->comboBoxUser2->Location = System::Drawing::Point(151, 32);
			this->comboBoxUser2->Name = L"comboBoxUser2";
			this->comboBoxUser2->Size = System::Drawing::Size(121, 21);
			this->comboBoxUser2->TabIndex = 1;
			// 
			// selectTwoUsers
			// 
			this->selectTwoUsers->AutoSize = true;
			this->selectTwoUsers->Location = System::Drawing::Point(94, 16);
			this->selectTwoUsers->Name = L"selectTwoUsers";
			this->selectTwoUsers->Size = System::Drawing::Size(85, 13);
			this->selectTwoUsers->TabIndex = 0;
			this->selectTwoUsers->Text = L"Select two users";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->listBoxRecommendations);
			this->groupBox2->Controls->Add(this->comboBoxSelectUser);
			this->groupBox2->Controls->Add(this->buttonShowRecommendations);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(382, 196);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(284, 173);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Recommendations";
			// 
			// listBoxRecommendations
			// 
			this->listBoxRecommendations->FormattingEnabled = true;
			this->listBoxRecommendations->Location = System::Drawing::Point(9, 19);
			this->listBoxRecommendations->Name = L"listBoxRecommendations";
			this->listBoxRecommendations->Size = System::Drawing::Size(142, 121);
			this->listBoxRecommendations->TabIndex = 10;
			// 
			// comboBoxSelectUser
			// 
			this->comboBoxSelectUser->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSelectUser->FormattingEnabled = true;
			this->comboBoxSelectUser->Location = System::Drawing::Point(157, 32);
			this->comboBoxSelectUser->Name = L"comboBoxSelectUser";
			this->comboBoxSelectUser->Size = System::Drawing::Size(121, 21);
			this->comboBoxSelectUser->TabIndex = 3;
			// 
			// buttonShowRecommendations
			// 
			this->buttonShowRecommendations->Location = System::Drawing::Point(149, 147);
			this->buttonShowRecommendations->Name = L"buttonShowRecommendations";
			this->buttonShowRecommendations->Size = System::Drawing::Size(129, 20);
			this->buttonShowRecommendations->TabIndex = 2;
			this->buttonShowRecommendations->Text = L"Show recommendations";
			this->buttonShowRecommendations->UseVisualStyleBackColor = true;
			this->buttonShowRecommendations->Click += gcnew System::EventHandler(this, &MyForm::buttonShowRecommendations_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(218, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Select user";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 381);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonRename);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxUser);
			this->Controls->Add(this->listBoxUsers);
			this->Controls->Add(this->labelUsers);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Friend Recommendations";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: 
	void RefreshUserLists() {
		listBoxUsers->Items->Clear();
		comboBoxUser1->Items->Clear();
		comboBoxUser2->Items->Clear();
		comboBoxSelectUser->Items->Clear();
		for each (String^ user in graph->Keys) {
			listBoxUsers->Items->Add(user);
			comboBoxUser1->Items->Add(user);
			comboBoxUser2->Items->Add(user);
			comboBoxSelectUser->Items->Add(user);
		}
	}
	void AddUserToGraph(String^ user) {
		if (String::IsNullOrWhiteSpace(user))
			return;
		if (!graph->ContainsKey(user)) {
			graph[user] = gcnew List<String^>();
			RefreshUserLists();
		}
	}
	void AddFriendshipToGraph(String^ a, String^ b) {
		if (String::IsNullOrWhiteSpace(a) || String::IsNullOrWhiteSpace(b) || a == b)
			return;

		if (!graph->ContainsKey(a) || !graph->ContainsKey(b))
			return;

		if (!graph[a]->Contains(b))
			graph[a]->Add(b);

		if (!graph[b]->Contains(a))
			graph[b]->Add(a);
	}
	void ShowRecommendationsFor(String^ user) {
		listBoxRecommendations->Items->Clear();
		if (!graph->ContainsKey(user))
			return;
		Dictionary<String^, int>^ recommendations = gcnew Dictionary<String^, int>();

		for each (String ^ friendName in graph[user]) {
			for each (String ^ candidate in graph[friendName])
				if (candidate != user && !graph[user]->Contains(candidate)) {
					if (!recommendations->ContainsKey(candidate))
						recommendations[candidate] = 0;
					recommendations[candidate]++;
				}
		}


		if (recommendations->Count == 0) {
			listBoxRecommendations->Items->Add("No recommendations");
			return;
		}
		for each (KeyValuePair<String^, int> pair in recommendations) {
			listBoxRecommendations->Items->Add(
				pair.Key + " - " + pair.Value.ToString() + " mutual friends");
		}
	}
	void DeleteUserFromGraph(String^ user) {
    if (String::IsNullOrWhiteSpace(user))
        return;

    if (!graph->ContainsKey(user))
        return;

    for each (String^ otherUser in graph->Keys) {
        if (otherUser != user) {
            graph[otherUser]->Remove(user);
        }
    }

    graph->Remove(user);
    RefreshUserLists();
    listBoxRecommendations->Items->Clear();
}
	void RenameUserInGraph(String^ oldName, String^ newName) {
		if (String::IsNullOrWhiteSpace(oldName) || String::IsNullOrWhiteSpace(newName) || oldName == newName)
			return;	
		if (!graph-> ContainsKey(oldName))
			return;
		if (graph->ContainsKey(newName))
			return;
		List<String^>^ oldFriends = gcnew List<String^>(graph[oldName]);

		graph[newName] = gcnew List<String^>(graph[oldName]);

		for each (String^ friendName in oldFriends) {
			if (graph->ContainsKey(friendName)) {
				graph[friendName]->Remove(oldName);
			}
			
			if (!graph[friendName]->Contains(newName))
				graph[friendName]->Add(newName);
		}
		graph->Remove(oldName);

		RefreshUserLists();
		listBoxRecommendations->Items->Clear();

		comboBoxUser1->SelectedItem = nullptr;
		comboBoxUser2->SelectedItem = nullptr;
		comboBoxSelectUser->SelectedItem = nullptr;
	}
};
}
